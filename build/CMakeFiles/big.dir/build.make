# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bignut/big-fluid-engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bignut/big-fluid-engine/build

# Include any dependencies generated for this target.
include CMakeFiles/big.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/big.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/big.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/big.dir/flags.make

CMakeFiles/big.dir/src/big_print.cpp.o: CMakeFiles/big.dir/flags.make
CMakeFiles/big.dir/src/big_print.cpp.o: ../src/big_print.cpp
CMakeFiles/big.dir/src/big_print.cpp.o: CMakeFiles/big.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bignut/big-fluid-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/big.dir/src/big_print.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/big.dir/src/big_print.cpp.o -MF CMakeFiles/big.dir/src/big_print.cpp.o.d -o CMakeFiles/big.dir/src/big_print.cpp.o -c /home/bignut/big-fluid-engine/src/big_print.cpp

CMakeFiles/big.dir/src/big_print.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/big.dir/src/big_print.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bignut/big-fluid-engine/src/big_print.cpp > CMakeFiles/big.dir/src/big_print.cpp.i

CMakeFiles/big.dir/src/big_print.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/big.dir/src/big_print.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bignut/big-fluid-engine/src/big_print.cpp -o CMakeFiles/big.dir/src/big_print.cpp.s

CMakeFiles/big.dir/src/main.cpp.o: CMakeFiles/big.dir/flags.make
CMakeFiles/big.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/big.dir/src/main.cpp.o: CMakeFiles/big.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bignut/big-fluid-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/big.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/big.dir/src/main.cpp.o -MF CMakeFiles/big.dir/src/main.cpp.o.d -o CMakeFiles/big.dir/src/main.cpp.o -c /home/bignut/big-fluid-engine/src/main.cpp

CMakeFiles/big.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/big.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bignut/big-fluid-engine/src/main.cpp > CMakeFiles/big.dir/src/main.cpp.i

CMakeFiles/big.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/big.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bignut/big-fluid-engine/src/main.cpp -o CMakeFiles/big.dir/src/main.cpp.s

# Object files for target big
big_OBJECTS = \
"CMakeFiles/big.dir/src/big_print.cpp.o" \
"CMakeFiles/big.dir/src/main.cpp.o"

# External object files for target big
big_EXTERNAL_OBJECTS =

big: CMakeFiles/big.dir/src/big_print.cpp.o
big: CMakeFiles/big.dir/src/main.cpp.o
big: CMakeFiles/big.dir/build.make
big: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_alphamat.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_barcode.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_dnn_objdetect.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_dnn_superres.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_face.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_hfs.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_img_hash.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_intensity_transform.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_mcc.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_quality.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_rapid.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_tracking.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_wechat_qrcode.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_text.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_video.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_dnn.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.4.5.4d
big: /usr/lib/x86_64-linux-gnu/libopencv_core.so.4.5.4d
big: CMakeFiles/big.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bignut/big-fluid-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable big"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/big.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/big.dir/build: big
.PHONY : CMakeFiles/big.dir/build

CMakeFiles/big.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/big.dir/cmake_clean.cmake
.PHONY : CMakeFiles/big.dir/clean

CMakeFiles/big.dir/depend:
	cd /home/bignut/big-fluid-engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bignut/big-fluid-engine /home/bignut/big-fluid-engine /home/bignut/big-fluid-engine/build /home/bignut/big-fluid-engine/build /home/bignut/big-fluid-engine/build/CMakeFiles/big.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/big.dir/depend

