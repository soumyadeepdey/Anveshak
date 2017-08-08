

#include "myheader.h"
#include "groundtruth.h"
#include "ui_groundtruth.h"
#include "QMessageBox"

/*---------------------------------Writng Final Output Files of Ground Truth-------------------------------------*/

IITkgp_functions::folder fol;

void writexml(char *xmlname, char *labelimage, int numlabel)
{
    IITkgp_functions::ImageProcFunc ipf;
  FILE *fp;
  char *name;
  fp = fopen(xmlname,"w");
  fprintf(fp,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");

    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);
      fprintf(fp,"<Anveshwak vertion=\"1.1\" date=\"%s\" >\n",buf);

      fprintf(fp,"\t<Document name =\"%s\" height =\"%d\" width =\"%d\">\n",imagename,src.rows,src.cols);
      fprintf(fp,"\t\t<Annotation name=\"%s\" labels=\"%d\"> \n",labelimage,numlabel);

      for(int i=0;i<Labels.size();i++)
      {
          string labelname = Labels[i].toUtf8().constData();
          name = (char *)malloc(4000*sizeof(char));
          strcpy(name,labelname.c_str());
          int number = ipf.NumberofForegroundPixel(LabelImages[i]);
          if(number > 0)
          {
              fprintf(fp,"\t\t\t<Labels name=\"%s\" index=\"%d\"> </Labels>\n",name,i);
          }

      }

      fprintf(fp,"\t\t</Annotation>\n");
      fprintf(fp,"\t</Document>\n");
      fprintf(fp,"</Anveshwak>");
      
      fclose(fp);

}

void IITkgp_functions::WriteOutput::FinalOutput(void)
{

    QMessageBox::information(0,"Final Output","All Processing Blocks are labelled and Writing the Final Label Output");

    printf("All Labeling Is Done\n");
    QString foldername;
    foldername =  QString::fromLocal8Bit(substring);
    char *name;


    IITkgp_functions::ImageProcFunc ipf;

    /*
    for(int i=0;i<Labels.size();i++)
    {

        int number = ipf.NumberofForegroundPixel(LabelImages[i]);
        if(number > 0)
        {
            QString s;
            //s = foldername+"_Label_"+Labels[i]+".png";
            s = "Label_"+Labels[i]+".png";
            string tes = s.toUtf8().constData();


            char *ss;


            ss = (char *)malloc(4000*sizeof(char));
            strcpy(ss,tes.c_str());

            name = (char *)malloc(4000*sizeof(char));
            name = fol.CreateNameIntoFolder(substring,ss);
            imwrite(name,LabelImages[i]);
        }
        //free(tempname);
        //free(name);


    }
*/


   // char *temps;
   // temps = (char *)malloc(4000*sizeof(char));
    //temps = substring;
    //strcat(temps,"_LabelAllInOne.png");


    name = (char *)malloc(4000*sizeof(char));
    //name = fol.CreateNameIntoFolder(substring,temps);
    name = fol.CreateNameIntoFolder(substring,"LabelAllInOne.png");
    char *labelimgname = name;

    imwrite(name,LabelImageInOne);

    LabelImageInOne.release();

  //





   // temps = (char *)malloc(4000*sizeof(char));
  //  temps = substring;
  //  strcat(temps,"_info.txt");

    name = (char *)malloc(4000*sizeof(char));
    name = fol.CreateNameIntoFolder(substring,"Imageinfo.txt");

    FILE *fp;
    fp = fopen(name,"w");


    fprintf(fp,"LabelName\tLabelNumber\tNumberOfPB\tNumberOfPixel\n");
    int numoflabels = 0;

    for(int i=0;i<Labels.size();i++)
    {
        string labelname = Labels[i].toUtf8().constData();
        name = (char *)malloc(4000*sizeof(char));
        strcpy(name,labelname.c_str());
        int number = ipf.NumberofForegroundPixel(LabelImages[i]);
        if(number > 0)
        {
            numoflabels = numoflabels + 1;
            fprintf(fp,"%s\t%d\t%d\t%d\n",name,i,LabelCount[i],number);
        }
    }
    fclose(fp);


    // Create XML File

    name = (char *)malloc(4000*sizeof(char));
    name = fol.CreateNameIntoFolder(substring,"Imageinfo.xml");
    writexml(name,labelimgname,numoflabels);


QMessageBox::information(0,"Final Output","All Processing are done");




/*************************************Release Memory************************************************/



    free(substring);
    free(tempname);

    contours.clear();
    hierarchy.clear();

    free(LabelFlag);
    free(LabelCount);

    for(int i=0;i<Labels.size();i++)
        free(LabelColor[i]);
    free(LabelColor);


    ColorLabelImage.release();

    Blocks.clear();
    src.release();
    src_binary.release();
    src_ub.release();
    src_gray.release();
    src_ROI.release();

    LabelImages.clear();






}
