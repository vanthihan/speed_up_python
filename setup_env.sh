#!/bin/bash

# Check if Python 3 is installed
if ! command -v python3 &> /dev/null; then
    echo "Python 3 is not installed. Please install it first."
    exit 1
fi

# Create a virtual environment
echo "Creating virtual environment..."
python3 -m venv my_env

# Activate the virtual environment
echo "Activating virtual environment..."
source my_env/bin/activate

# Upgrade pip to the latest version
echo "Upgrading pip..."
pip install --upgrade pip

# Install required packages
echo "Installing required packages from requirements.txt..."
pip install -r requirements.txt

echo "Setup complete. To activate the environment, run:"
echo "source my_env/bin/activate"
