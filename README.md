# 🖥️ C++ DB- Device Benchmarking Record Management

This project is a command-line interface (CLI) tool to maintain records in a CSV file. It allows you to add, update, modify, and remove records used for benchmarking multiple devices such as mobile phones, laptops, and PCs. This project is implemented solely using C++ and its file handling capabilities.

## Requirements

- C++ compiler (e.g., g++)
- Standard C++ libraries

## CSV Format

The CSV file (data.csv) should follow this format:
day, name, CPU, GPU, MEMORY, geekbench, DMark, cenebench, crystalDiskMark, mspeed, battery, storage, RAM

Example row:
2024/07/17, Oman , Intel i7, NVIDIA GTX 3080, 16, 15000, 2500, 3000, 1000, 500, 95 , 1024, 32

## Download

The latest release of this project can be found [here](https://github.com/Gunavarthan/CPP---DB/releases/latest).

## 🗒️ Notes

- This program creates and operates on the data.csv file in the same directory.
- Open data.csv with Excel or any CSV viewer to analyze benchmarking data visually.
