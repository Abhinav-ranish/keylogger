# Windows Keylogger and Webhook Logger for Cybersecurity Research

This project is a Windows-based keylogging tool developed for **cybersecurity research and educational purposes only**. It demonstrates how keystrokes are recorded on a Windows system and how they can be transmitted to a specified server or endpoint via webhooks. This repository serves as an educational resource to study potential vulnerabilities, ethical hacking practices, and system security measures.

> **Disclaimer:** This code is strictly for research purposes. Unauthorized use of keyloggers is illegal and unethical. Please ensure you have permission to use this tool in any environment.

## Features

- **Keystroke Logging**: Records keystrokes from a Windows environment, identifying and storing special keys (e.g., ALT, SHIFT, ESC).
- **Webhook Transmission**: Sends captured keystroke data to a Discord webhook endpoint using the `libcurl` library.
- **File-Based Logging**: Stores keystrokes in a text file (`keystrokes.txt`) for local record-keeping.
- **Hidden Window Execution**: Hides the console window during execution to operate discreetly for testing purposes.

## File Structure

- **main.c**: The main program file, containing functions for keystroke logging, special key detection, and webhook transmission.
- **keystrokes.txt**: The output file where captured keystrokes are stored.

## Setup and Dependencies

This project requires **Windows OS** and is dependent on the **cURL library** to enable HTTP requests.

### Prerequisites

- **cURL Library**: Install cURL for handling HTTP requests to send data via webhook.
- **Windows SDK**: This project requires Windows-specific headers (`windows.h`, `winuser.h`) and functions.

### Compilation

Compile the program using a Windows-compatible C compiler, such as GCC for Windows (MinGW).

```bash
gcc main.c -o keylogger -lws2_32 -lcurl
```

## Usage

1. **Set the Webhook URL**: Update the `webhook_url` variable with your own Discord webhook URL.
2. **Run the Program**: Execute the program to start capturing keystrokes.

```bash
keylogger.exe
```

3. **Analyze the Data**: After running, check `keystrokes.txt` for captured keystrokes, or monitor the specified webhook endpoint.

### Example Output

The keystrokes are recorded in `keystrokes.txt` in the following format:

```
[ALT]Hello World[ENTER][BACKSPACE]Example Text
```

## Legal Notice

This tool is intended exclusively for authorized cybersecurity research and educational purposes. Unauthorized or malicious use of keylogging tools is illegal and may lead to criminal charges. **Always obtain proper permissions before using in any environment.**

## License

Licensed under the MIT License.

