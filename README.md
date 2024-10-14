# Sorting Algorithm Visualizer

This project is a graphical sorting algorithm visualizer built using **C++** and **SDL2**. It allows you to visualize how different sorting algorithms work by sorting an array of randomly generated integers. The project supports multiple sorting algorithms, which can be selected using keyboard inputs.

## Features

- Visualizes various sorting algorithms:
  - Selection Sort
  - Insertion Sort
  - Bubble Sort
  - Merge Sort
  - Quick Sort
- Randomly generates a new array to sort.
- Displays real-time sorting progress using graphical bars.
- Handles different key inputs to trigger sorting algorithms or generate a new array.

## Controls

- **Press `0`**: Generate a new random list.
- **Press `1`**: Start **Selection Sort**.
- **Press `2`**: Start **Insertion Sort**.
- **Press `3`**: Start **Bubble Sort**.
- **Press `4`**: Start **Merge Sort**.
- **Press `5`**: Start **Quick Sort**.
- **Press `Q`**: Quit the program.

## Prerequisites

To compile and run this project, you need to install **SDL2**. You can download and install it from the [SDL2 official website](https://www.libsdl.org/).

## Setting Up SDL2

1. **Install SDL2**: Follow the installation instructions specific to your platform (Windows, Linux, or macOS).
2. **Link SDL2**: Ensure that your compiler can find the SDL2 library. Update the include and linker flags as required.
   - For example, if you are using GCC on Linux, your compilation command may look like:
     ```bash
     g++ -o SortingVisualizer main.cpp -lSDL2
     ```
   - On Windows (using MinGW):
     ```bash
     g++ -o SortingVisualizer.exe main.cpp -IC:\path\to\SDL2\include -LC:\path\to\SDL2\lib -lmingw32 -lSDL2main -lSDL2
     ```

## Running the Program

Once the project is compiled:

1. Open a terminal or command prompt.
2. Run the executable (e.g., `./SortingVisualizer` on Linux/macOS or `SortingVisualizer.exe` on Windows).
3. Use the keyboard controls as mentioned above to interact with the visualizer.

## Project Structure

