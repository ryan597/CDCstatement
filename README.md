# Crypto.Com Statement Processing
Repository for processing the CSV transaction files downloaded from a Crypto.com account.

---

## Contents

[Crypto.Com Statement Processing](#crypto.com-statement-processing)

- [1. Dependencies](#1-dependencies)
- [2. Folder Structure](#2-folder-structure)
- [3. Building](#3-building)
- [4. Usage](#4-usage)

---

## 1. Dependencies

## 2. Folder Structure

## 3. Building

This project is supplied with a makefile that will compile the binary executable for you.
To run the makefile, from the terminal in the folder directory run the command

```bash
make
```

To clean up the object files, you can run the command

```bash
make clean
```

To remove the binary executable and the object files, you can run the command

```bash
make remove
```


## 4. Usage

To run the program, from the terminal you enter the command

```bash
./run <name of csv file>
```

where you can optionally supply the program with the transaction statement csv file that you want analysed. If the csv file is not supplied, you will be prompted for it once the program is run.
If the csv file is stored in the Statement/ foler, you do not need to give the statement/ prefix, nor should you enter the ".csv" extension. These are assumed by the program for ease of usage.

Within the program you can also be prompted for several other actions.

1. Print account balance
2. Check Investments
3. Enter a new statement
4. Exit the program

---

## [License](LICENSE)

<details>
<summary>MIT License</summary>

Copyright (c) 2021 Ryan Smith

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
</details>

---
