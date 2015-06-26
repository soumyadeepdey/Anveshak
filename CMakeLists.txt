cmake_minimum_required(VERSION 2.8)
project( Anveshak )
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_PREFIX_PATH  /home/soumyadeep/Qt5.3.1/5.3/gcc_64/lib/cmake/Qt5Widgets)
find_package(Qt5Widgets)
# Add the include directories for the Qt 5 Widgets module to
# the compile lines.
include_directories(${Qt5Widgets_INCLUDE_DIRS})

# Use the compile definitions defined in the Qt 5 Widgets module
add_definitions(${Qt5Widgets_DEFINITIONS})
set(CMAKE_PREFIX_PATH  /home/soumyadeep/Qt5.3.1/5.3/gcc_64/lib/cmake/Qt5Core)
find_package(Qt5Core)
# Add the include directories for the Qt 5 Widgets module to
# the compile lines.
include_directories(${Qt5Core_INCLUDE_DIRS})

# Use the compile definitions defined in the Qt 5 Widgets module
add_definitions(${Qt5Core_DEFINITIONS})
set(CMAKE_PREFIX_PATH  /home/soumyadeep/Qt5.3.1/5.3/gcc_64/lib/cmake/Qt5Gui)
find_package(Qt5Gui)
# Add the include directories for the Qt 5 Widgets module to
# the compile lines.
include_directories(${Qt5Gui_INCLUDE_DIRS})

# Use the compile definitions defined in the Qt 5 Widgets module
add_definitions(${Qt5Gui_DEFINITIONS})
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
find_package( OpenCV REQUIRED )

SET(Anveshak_SOURCES  main.cpp connectedcomponent.cpp Morphology.cpp SmoothingGapfilling.cpp folder.cpp binarization.cpp Image_proc_functions.cpp RectangleTest.cpp PixelValidation.cpp binary.cpp rebinarization.cpp preprocessingblock.cpp CreateProcessingBlocks.cpp undopreprocessing.cpp labelinfo.cpp customizelabels.cpp selectlabel.cpp SelectROI.cpp continue.cpp groundtruth.cpp labelprocessingblocks.cpp wanttorelabelroi.cpp relabelchoosingroi.cpp FinalOutput.cpp LabelingOfPb.cpp LabellingROI.cpp selectroilabellingtype.cpp GiveLabelPBofROI.cpp updatelabelasking.cpp )
SET(Anveshak_HEADERS myheader.h binary.h rebinarization.h preprocessingblock.h undopreprocessing.h labelinfo.h customizelabels.h selectlabel.h continue.h groundtruth.h labelprocessingblocks.h wanttorelabelroi.h relabelchoosingroi.h selectroilabellingtype.h updatelabelasking.h)  
SET(Anveshak_FORMS binary.ui rebinarization.ui preprocessingblock.ui undopreprocessing.ui labelinfo.ui customizelabels.ui selectlabel.ui continue.ui groundtruth.ui labelprocessingblocks.ui wanttorelabelroi.ui relabelchoosingroi.ui selectroilabellingtype.ui updatelabelasking.ui)  
#QT5_WRAP_CPP(Anveshak_HEADERS_MOC ${Anveshak_HEADERS})
#QT5_WRAP_UI(Anveshak_FORMS_HEADERS ${Anveshak_FORMS})

# Or set it globally for all targets:
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

ADD_EXECUTABLE(Anveshak ${Anveshak_SOURCES} ${Anveshak_HEADERS} ${Anveshak_FORMS})
TARGET_LINK_LIBRARIES(Anveshak  Qt5::Widgets Qt5::Core Qt5::Gui ${OpenCV_LIBS})
set(CMAKE_BUILD_TYPE Debug)

