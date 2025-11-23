cmake_minimum_required(VERSION 3.19)
project(medi_track_2 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Quick)

qt_standard_project_setup()

qt_add_executable(medi_track_2
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    myresources.qrc
    signup.h signup.cpp signup.ui
    mainmenu.h mainmenu.cpp mainmenu.ui

    patient.h patient.cpp
    appointment.h appointment.cpp
    medicine.h medicine.cpp
    day.h day.cpp
    caretaker.h caretaker.cpp
    queue.h
    month.h month.cpp
    addmediciaddmedicineaddmedicine.ui addmedicine.ui
    addmoredetails.h addmoredetails.cpp addmoredetails.ui

    graphshow.h graphshow.cpp graphshow.ui
    calorieintake.h calorieintake.cpp
    addmedicine.h addmedicine.cpp addmedicine.ui

)

target_link_libraries(medi_track_2
    PRIVATE
        Qt::Core
        Qt::Widgets
)
target_link_libraries(medi_track_2 PRIVATE Qt6::Core Qt6::Widgets Qt6::Quick)

include(GNUInstallDirs)

install(TARGETS medi_track_2
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET medi_track_2
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
