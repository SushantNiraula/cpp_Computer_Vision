## Learning Computer vision with OpenCV C++

### Exercise 1:
We are starting with exercise 1 where we setup the opencv in my macbook. 
1. Start with installing vscode. 
2. Then install extensions of C/C++ from extensions in Visual Studio Code.
3. Install C/C++ in macos using xcode as:
    >> xcode-select --install
4. Install the cmake and opencv which are required for your project. 
    brew install cmake opencv 
5. Verify the installation of c++ and opencv with:

    >> c++ --version

        `Apple clang version 17.0.0 (clang-1700.6.4.2)

        Target: arm64-apple-darwin25.3.0

        Thread model: posix

        InstalledDir: /Library/Developer/CommandLineTools/usr/bin`
    
    >> pkg-config --modversion opencv4

    `4.13.0`

6. Now create a folder for your work and then create `main.cpp` and `CMakeLists.txt` files.
7. Create build folder with 
    >>mkdir build
8. Then create your CMake file as:

    ```
    cmake_minimum_required(VERSION 3.10)

    # Name your project
    project(VisionTest)

    # Require C++ 14 or higher (standard for modern OpenCV)
    set(CMAKE_CXX_STANDARD 14)

    # Find the OpenCV package installed by Homebrew
    find_package(OpenCV REQUIRED)

    # Tell CMake to include the OpenCV header directories
    include_directories(${OpenCV_INCLUDE_DIRS})

    # Create an executable from your main.cpp file
    add_executable(VisionTest main.cpp)

    # Link the pre-compiled OpenCV libraries to your executable
    target_link_libraries(VisionTest ${OpenCV_LIBS})
    ```
9. Then write the code in main file. In exercise 1 we will be writing a code where the code opens the file in the directory and then displays it to the user. 

10. After you finish writing the code then you must build it for this you do following steps:

    ```
    >> cd build
    >> cmake .. 
        // Because your cmake file is in one directory below build directory.
    >> make 
        To run the program we use:
    >> ./VisionTest

#### Note::
    If your vscode doesn't recognize <opencv2/opencv.hpp> then you must follow following steps to solve the issue:

    1. If you installed OpenCV using Homebrew, you can find the installation prefix by running the following command in your terminal:
        >> brew --prefix opencv
    2. Open the VS Code C/C++ configurations:
        * Open the Command Palette in VS Code by pressing `Cmd + Shift + P`.
        * Search for and select C/C++: Edit Configurations (JSON). This will open the `c_cpp_properties.json` file.
    3. Add the include path to c_cpp_properties.json:
        ```
        "includePath": [
            "${workspaceFolder}/**",
            "/opt/homebrew/opt/opencv/include/opencv4" 
        ],
        ```
### Exercise 2:
    In this exercise we will learn to open a videoCapture to capture the webcam feed of the laptop. Then display it if the VideoCapture is sucessful. We test the capture is sucessfull or not using `cap.isOpened()` method of cap object. Then we run a infinite loop and there we use `imshow()` to display the captured frame which is transfered from `cap>>frame`. Then we wait 1 ms to see if user pressed `'q'`. If yes then we reuturn -1 and exit else not. 

    I further added a else block to see if the videoCapture is not sucessful than gracefully through cerr as it is. 

### Exercise 3:

    