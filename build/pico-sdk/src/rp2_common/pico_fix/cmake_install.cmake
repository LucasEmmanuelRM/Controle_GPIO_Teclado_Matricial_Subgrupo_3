<<<<<<< HEAD
# Install script for directory: C:/Users/Windows 10/.pico-sdk/sdk/2.1.0/src/rp2_common/pico_fix
=======
# Install script for directory: C:/Users/gabri/.pico-sdk/sdk/2.1.0/src/rp2_common/pico_fix
>>>>>>> main

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Controle_GPIO_Teclado_Matricial_Subgrupo_3")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
<<<<<<< HEAD
  set(CMAKE_OBJDUMP "C:/Users/Windows 10/.pico-sdk/toolchain/13_3_Rel1/bin/arm-none-eabi-objdump.exe")
=======
  set(CMAKE_OBJDUMP "C:/Users/gabri/.pico-sdk/toolchain/13_3_Rel1/bin/arm-none-eabi-objdump.exe")
>>>>>>> main
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
<<<<<<< HEAD
  include("C:/Workspace/Embarcatech/PROJETO GPIO COM TECLADO MATRICIAL/Controle_GPIO_Teclado_Matricial_Subgrupo_3/build/pico-sdk/src/rp2_common/pico_fix/rp2040_usb_device_enumeration/cmake_install.cmake")
=======
  include("D:/Embarcatech/Repositorio - teclado/Controle_GPIO_Teclado_Matricial_Subgrupo_3/build/pico-sdk/src/rp2_common/pico_fix/rp2040_usb_device_enumeration/cmake_install.cmake")
>>>>>>> main
endif()

