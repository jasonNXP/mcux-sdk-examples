SET(CMAKE_ASM_FLAGS_DEBUG " \
    -DDEBUG \
    -D__STARTUP_CLEAR_BSS \
    -g \
    -mcmse \
    -mcpu=cortex-m33 \
    -Wall \
    -mfloat-abi=hard \
    -mfpu=fpv5-sp-d16 \
    -mthumb \
    -fno-common \
    -ffunction-sections \
    -fdata-sections \
    -ffreestanding \
    -fno-builtin \
    -mapcs \
    -std=gnu99 \
")
SET(CMAKE_ASM_FLAGS_RELEASE " \
    -DNDEBUG \
    -D__STARTUP_CLEAR_BSS \
    -mcmse \
    -mcpu=cortex-m33 \
    -Wall \
    -mfloat-abi=hard \
    -mfpu=fpv5-sp-d16 \
    -mthumb \
    -fno-common \
    -ffunction-sections \
    -fdata-sections \
    -ffreestanding \
    -fno-builtin \
    -mapcs \
    -std=gnu99 \
")
SET(CMAKE_C_FLAGS_DEBUG " \
    -DDEBUG \
    -DDEMO_CODE_START_NS=65536 \
    -DCPU_LPC55S69JBD100_cm33_core0 \
    -DSERIAL_PORT_TYPE_UART=1 \
    -g \
    -O0 \
    -mcmse \
    -mcpu=cortex-m33 \
    -Wall \
    -mfloat-abi=hard \
    -mfpu=fpv5-sp-d16 \
    -mthumb \
    -MMD \
    -MP \
    -fno-common \
    -ffunction-sections \
    -fdata-sections \
    -ffreestanding \
    -fno-builtin \
    -mapcs \
    -std=gnu99 \
")
SET(CMAKE_C_FLAGS_RELEASE " \
    -DNDEBUG \
    -DDEMO_CODE_START_NS=65536 \
    -DCPU_LPC55S69JBD100_cm33_core0 \
    -DSERIAL_PORT_TYPE_UART=1 \
    -Os \
    -mcmse \
    -mcpu=cortex-m33 \
    -Wall \
    -mfloat-abi=hard \
    -mfpu=fpv5-sp-d16 \
    -mthumb \
    -MMD \
    -MP \
    -fno-common \
    -ffunction-sections \
    -fdata-sections \
    -ffreestanding \
    -fno-builtin \
    -mapcs \
    -std=gnu99 \
")
SET(CMAKE_CXX_FLAGS_DEBUG " \
    -DDEBUG \
    -DCPU_LPC55S69JBD100_cm33_core0 \
    -DSERIAL_PORT_TYPE_UART=1 \
    -g \
    -O0 \
    -mcmse \
    -mcpu=cortex-m33 \
    -Wall \
    -mfloat-abi=hard \
    -mfpu=fpv5-sp-d16 \
    -mthumb \
    -MMD \
    -MP \
    -fno-common \
    -ffunction-sections \
    -fdata-sections \
    -ffreestanding \
    -fno-builtin \
    -mapcs \
    -fno-rtti \
    -fno-exceptions \
")
SET(CMAKE_CXX_FLAGS_RELEASE " \
    -DNDEBUG \
    -DCPU_LPC55S69JBD100_cm33_core0 \
    -DSERIAL_PORT_TYPE_UART=1 \
    -Os \
    -mcmse \
    -mcpu=cortex-m33 \
    -Wall \
    -mfloat-abi=hard \
    -mfpu=fpv5-sp-d16 \
    -mthumb \
    -MMD \
    -MP \
    -fno-common \
    -ffunction-sections \
    -fdata-sections \
    -ffreestanding \
    -fno-builtin \
    -mapcs \
    -fno-rtti \
    -fno-exceptions \
")
SET(CMAKE_EXE_LINKER_FLAGS_DEBUG " \
    -Wl,--cmse-implib \
    -Wl,--out-implib=./debug/freertos_mpu_s_CMSE_lib.o \
    -g \
    -mcpu=cortex-m33 \
    -Wall \
    -mfloat-abi=hard \
    -mfpu=fpv5-sp-d16 \
    --specs=nano.specs \
    --specs=nosys.specs \
    -fno-common \
    -ffunction-sections \
    -fdata-sections \
    -ffreestanding \
    -fno-builtin \
    -mthumb \
    -mapcs \
    -Xlinker \
    --gc-sections \
    -Xlinker \
    -static \
    -Xlinker \
    -z \
    -Xlinker \
    muldefs \
    -Xlinker \
    -Map=output.map \
    -T${ProjDirPath}/LPC55S69_cm33_core0_flash_s.ld -static \
")
SET(CMAKE_EXE_LINKER_FLAGS_RELEASE " \
    -Wl,--cmse-implib \
    -Wl,--out-implib=./release/freertos_mpu_s_CMSE_lib.o \
    -mcpu=cortex-m33 \
    -Wall \
    -mfloat-abi=hard \
    -mfpu=fpv5-sp-d16 \
    --specs=nano.specs \
    --specs=nosys.specs \
    -fno-common \
    -ffunction-sections \
    -fdata-sections \
    -ffreestanding \
    -fno-builtin \
    -mthumb \
    -mapcs \
    -Xlinker \
    --gc-sections \
    -Xlinker \
    -static \
    -Xlinker \
    -z \
    -Xlinker \
    muldefs \
    -Xlinker \
    -Map=output.map \
    -T${ProjDirPath}/LPC55S69_cm33_core0_flash_s.ld -static \
")