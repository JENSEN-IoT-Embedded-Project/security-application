#wifi.h



#hcrs04.h

add_library(hcsr04 STATIC hcsr04.c)
target_include_directories(hcsr04 PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(hcsr04
    pico_stdlib
    hardware_gpio
)

#main
set(exec motionsensor)
add_executable(${exec} main.c)
pico_enable_stdio_usb(${exec} 1)
pico_enable_stdio_uart(${exec} 0)
pico_add_extra_outputs(${exec})

target_link_libraries(motionsensor 
    pico_stdlib
    hardware_gpio
    pico_time
    hcsr04
)



