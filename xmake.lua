-- 设置项目名称和编译标准
set_project("can_42motor_project")
set_languages("c11", "cxx11")


-- 指定工具链路径，例如 /path/to/your/arm-none-eabi/bin
toolchain("arm-none-eabi")
    -- 标记为独立工具链
    set_kind("standalone")
    -- 定义交叉编译工具链地址
    set_sdkdir("D:\\gcc-arm-none-eabi\\10 2021.10")
    set_toolset("cc", "arm-none-eabi-gcc")
    set_toolset("cxx", "arm-none-eabi-g++")
    set_toolset("as", "arm-none-eabi-gcc")
    set_toolset("ld", "arm-none-eabi-ld")
    --set_bindir("C:\\Program Files (x86)\\GNU Arm Embedded Toolchain\\10 2021.10\\bin")
toolchain_end()

-- 设置编译模式
add_rules("mode.debug", "mode.release")

if is_mode("release") then
    set_optimize("smallest")
else
    set_optimize("none")
    set_symbols("debug")
end

-- 定义目标
target("can_motor_project")
    set_kind("binary")
    set_toolchains("arm-none-eabi")
    set_plat("cross")
    set_arch("m7")
--     set_filename("demo.elf")
    add_defines("USE_HAL_DRIVER", "STM32H723xx")
    -- MCU-specific flags
    local target_flags = "-mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard"

    -- 添加编译选项
    add_cflags(target_flags, "-Wall", "-Wextra", "-Wpedantic", "-fdata-sections", "-ffunction-sections", {force = true})

    -- 根据构建类型添加不同的优化选项
    if is_mode("debug") then
        add_cflags("-O0", "-g3")
    elseif is_mode("release") then
        add_cflags("-Os", "-g0")
    end

    add_asflags(target_flags, "-x assembler-with-cpp", "-MMD", "-MP", {force = true})
    add_cxxflags(target_flags, "-fno-rtti", "-fno-exceptions", "-fno-threadsafe-statics", {force = true})

    -- 设置链接选项
    -- Linker script path
    local ld_script = path.join(os.scriptdir(), "STM32H723VGTx_FLASH.ld")

    -- Linker flags
    add_ldflags(target_flags,
                "-T", ld_script,
                "--specs=nano.specs",
                "-Wl,-Map=$(project).map",
                "-Wl,--gc-sections",
                "-Wl,--start-group", "-lc", "-lm", "-Wl,--end-group",
                "-Wl,--print-memory-usage")

    -- C++ specific linker flags
    add_ldflags( "-lstdc++", "-lsupc++", "-Wl,--end-group", { force = true })


    add_includedirs(
        "../../Core/Inc",
        "../../Drivers/STM32H7xx_HAL_Driver/Inc",
        "../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy",
        "../../Middlewares/Third_Party/FreeRTOS/Source/include",
        "../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS",
        "../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F",
        "../../Drivers/CMSIS/Device/ST/STM32H7xx/Include",
        "../../Drivers/CMSIS/Include"
    )

    -- 添加源文件
    add_files(
        "../../Core/Src/main.c",
        "../../Core/Src/gpio.c",
        "../../Core/Src/freertos.c",
        "../../Core/Src/fdcan.c",
        "../../Core/Src/memorymap.c",
        "../../Core/Src/stm32h7xx_it.c",
        "../../Core/Src/stm32h7xx_hal_msp.c",
        "../../Core/Src/stm32h7xx_hal_timebase_tim.c",
        "../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.c",
        "../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_fdcan.c",
        "../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.c",
        "../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.c",
        "../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.c",
        "../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.c",
        "../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.c",
        "../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.c",
        "../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.c",
        "../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.c",
        "../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.c",
        "../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.c",
        "../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.c",
        "../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.c",
        "../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.c",
        "../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.c",
        "../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.c",
        "../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.c",
        "../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.c",
        "../../Core/Src/system_stm32h7xx.c",
        "../../Middlewares/Third_Party/FreeRTOS/Source/croutine.c",
        "../../Middlewares/Third_Party/FreeRTOS/Source/event_groups.c",
        "../../Middlewares/Third_Party/FreeRTOS/Source/list.c",
        "../../Middlewares/Third_Party/FreeRTOS/Source/queue.c",
        "../../Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.c",
        "../../Middlewares/Third_Party/FreeRTOS/Source/tasks.c",
        "../../Middlewares/Third_Party/FreeRTOS/Source/timers.c",
        "../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c",
        "../../Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c",
        "../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c",
        "../../Core/Src/sysmem.c",
        "../../Core/Src/syscalls.c",
        "../../startup_stm32h723xx.s"
    )
    -- 添加头文件目录
    add_includedirs("Core/Inc",
                    "Drivers/STM32H7xx_HAL_Driver/Inc",
                    "Drivers/STM32H7xx_HAL_Driver/Inc/Legacy",
                    "Middlewares/Third_Party/FreeRTOS/Source/include",
                    "Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS",
                    "Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F",
                    "Drivers/CMSIS/Device/ST/STM32H7xx/Include",
                    "Drivers/CMSIS/Include",
                    "Own/App",
                    "Own/App/Imu/BMI088/inc",
                    "Own/Bsp",
                    "Own/Moudle",
                    "Own/Obj",
                    "Own/Thread",
                    "Own/Heap")

    -- 添加源文件
    add_files("Core/Src/*.c")
    add_files("Drivers/STM32H7xx_HAL_Driver/Src/*.c")
    add_files("Middlewares/Third_Party/FreeRTOS/Source/*.c")
    add_files("startup_stm32h723xx.s")
    add_files("Own/App/*.c", "Own/App/*.cpp", "Own/Bsp/*.c", "Own/Bsp/*.cpp", "Own/Moudle/*.c", "Own/Moudle/*.cpp", "Own/Obj/*.c", "Own/Obj/*.cpp", "Own/Thread/*.c", "Own/Thread/*.cpp", "Own/Heap/*.c", "Own/Heap/*.cpp")
