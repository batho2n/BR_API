# 3D Audio Bianural Rendering for VR device of CISS
#
## 1. Build 
+ HRTF Header file generation for BR api
+ Compile and generate library file (libs/libBR_api.a) and demo file (bin/BR_demo)
+ Must be installed python 2.7 in your computer
+
+ BR_api>make
+ 
+ Outputs
+ [Directory]
+ libs		: Libary file
+ bin		: Demo file and test output
+ [Files]
+ libs/libBR_api.a	: API Library file
+ bin/BR_demo		: BR API demo file
+
+
## 2. Test
+ Test the 3D Audio rendering using bin/BR_demo file and test/sample.wav
+ Must be installed sox in your computer
+
+ BR_API>make test
+
+ Outputs
+ [Files]
+ bin/sample_out.wav	: Bianural rendering result (44.1kHz, 16 bit, Stereo)
+ 
+ If you wnat to render by other direction, refer to Usage of bin/BR_demo
+ BR_api>./bin/BR_demo


## 3. Clean
+ Clean the BR_api directory
+
+ BR_api>make clean
