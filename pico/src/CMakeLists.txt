#hcrs04.h library
add_library(hcsr04 STATIC hcsr04.c)
target_include_directories(hcsr04 PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(hcsr04
    pico_stdlib
    hardware_gpio
)

#executable
add_executable(security-application main.c) #wifi.c 
target_include_directories(security-application PRIVATE ${CMAKE_SOURCE_DIR}/include)
set_target_properties(security-application PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 1)

target_link_libraries(security-application 
    pico_stdlib
    harwdare_gpio
    pico_time
    hcsr04
    pico_cyw43_arch_lwip_threadsafe_background
)

pico_add_extra_outputs(security-application)
