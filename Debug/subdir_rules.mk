################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-1673184767: ../car.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs2020/ccs/utils/sysconfig_1.24.0/sysconfig_cli.bat" --script "C:/Users/Alan/workspace_ccstheia/car_demo/car.syscfg" -o "." -s "D:/TI/mspm0_sdk_2_05_01_00/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-1673184767 ../car.syscfg
device.opt: build-1673184767
device.cmd.genlibs: build-1673184767
ti_msp_dl_config.c: build-1673184767
ti_msp_dl_config.h: build-1673184767
Event.dot: build-1673184767

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/Alan/workspace_ccstheia/car_demo" -I"C:/Users/Alan/workspace_ccstheia/car_demo/Debug" -I"D:/TI/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"D:/TI/mspm0_sdk_2_05_01_00/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: D:/TI/mspm0_sdk_2_05_01_00/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/Alan/workspace_ccstheia/car_demo" -I"C:/Users/Alan/workspace_ccstheia/car_demo/Debug" -I"D:/TI/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"D:/TI/mspm0_sdk_2_05_01_00/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/Alan/workspace_ccstheia/car_demo" -I"C:/Users/Alan/workspace_ccstheia/car_demo/Debug" -I"D:/TI/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"D:/TI/mspm0_sdk_2_05_01_00/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


