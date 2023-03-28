if (NOT EXISTS "/home/ulisesten/Documents/android-project/app/.cxx/Debug/295y3y4e/x86/install_manifest.txt")
    message(FATAL_ERROR "Cannot find install manifest: \"/home/ulisesten/Documents/android-project/app/.cxx/Debug/295y3y4e/x86/install_manifest.txt\"")
endif(NOT EXISTS "/home/ulisesten/Documents/android-project/app/.cxx/Debug/295y3y4e/x86/install_manifest.txt")

file(READ "/home/ulisesten/Documents/android-project/app/.cxx/Debug/295y3y4e/x86/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")
foreach (file ${files})
    message(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
    execute_process(
        COMMAND /run/media/ulisesten/SSD2/Aplicaciones/android-studio-2020.3.1.25-linux/Sdk/cmake/3.10.2.4988404/bin/cmake -E remove "$ENV{DESTDIR}${file}"
        OUTPUT_VARIABLE rm_out
        RESULT_VARIABLE rm_retval
    )
    if(NOT ${rm_retval} EQUAL 0)
        message(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
    endif (NOT ${rm_retval} EQUAL 0)
endforeach(file)

