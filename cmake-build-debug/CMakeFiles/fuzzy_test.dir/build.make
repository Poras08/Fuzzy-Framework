# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\poras\Downloads\Fuzzy Framework"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\poras\Downloads\Fuzzy Framework\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\fuzzy_test.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\fuzzy_test.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\fuzzy_test.dir\flags.make

CMakeFiles\fuzzy_test.dir\main.cpp.obj: CMakeFiles\fuzzy_test.dir\flags.make
CMakeFiles\fuzzy_test.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\poras\Downloads\Fuzzy Framework\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fuzzy_test.dir/main.cpp.obj"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\fuzzy_test.dir\main.cpp.obj /FdCMakeFiles\fuzzy_test.dir\ /FS -c "C:\Users\poras\Downloads\Fuzzy Framework\main.cpp"
<<

CMakeFiles\fuzzy_test.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fuzzy_test.dir/main.cpp.i"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe > CMakeFiles\fuzzy_test.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\poras\Downloads\Fuzzy Framework\main.cpp"
<<

CMakeFiles\fuzzy_test.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fuzzy_test.dir/main.cpp.s"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\fuzzy_test.dir\main.cpp.s /c "C:\Users\poras\Downloads\Fuzzy Framework\main.cpp"
<<

# Object files for target fuzzy_test
fuzzy_test_OBJECTS = \
"CMakeFiles\fuzzy_test.dir\main.cpp.obj"

# External object files for target fuzzy_test
fuzzy_test_EXTERNAL_OBJECTS =

fuzzy_test.exe: CMakeFiles\fuzzy_test.dir\main.cpp.obj
fuzzy_test.exe: CMakeFiles\fuzzy_test.dir\build.make
fuzzy_test.exe: CMakeFiles\fuzzy_test.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\poras\Downloads\Fuzzy Framework\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fuzzy_test.exe"
	"E:\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\fuzzy_test.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\fuzzy_test.dir\objects1.rsp @<<
 /out:fuzzy_test.exe /implib:fuzzy_test.lib /pdb:"C:\Users\poras\Downloads\Fuzzy Framework\cmake-build-debug\fuzzy_test.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\fuzzy_test.dir\build: fuzzy_test.exe

.PHONY : CMakeFiles\fuzzy_test.dir\build

CMakeFiles\fuzzy_test.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\fuzzy_test.dir\cmake_clean.cmake
.PHONY : CMakeFiles\fuzzy_test.dir\clean

CMakeFiles\fuzzy_test.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\poras\Downloads\Fuzzy Framework" "C:\Users\poras\Downloads\Fuzzy Framework" "C:\Users\poras\Downloads\Fuzzy Framework\cmake-build-debug" "C:\Users\poras\Downloads\Fuzzy Framework\cmake-build-debug" "C:\Users\poras\Downloads\Fuzzy Framework\cmake-build-debug\CMakeFiles\fuzzy_test.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\fuzzy_test.dir\depend
