#!/bin/bash

# Проверка и установка LD_LIBRARY_PATH
if [[ -z "$LD_LIBRARY_PATH" ]]; then
    export LD_LIBRARY_PATH=/usr/local/systemc-3.0.1/lib-linux64
    echo "LD_LIBRARY_PATH successfully set to: $LD_LIBRARY_PATH"
else
    if [[ ":$LD_LIBRARY_PATH:" != *":/usr/local/systemc-3.0.1/lib-linux64:"* ]]; then
        export LD_LIBRARY_PATH=/usr/local/systemc-3.0.1/lib-linux64:$LD_LIBRARY_PATH
        echo "LD_LIBRARY_PATH successfully updated to: $LD_LIBRARY_PATH"
    else
        echo "/usr/local/systemc-3.0.1/lib-linux64 already exists in LD_LIBRARY_PATH: $LD_LIBRARY_PATH"
    fi
fi

# Проверка и установка PATH
if [[ ":$PATH:" != *":/opt/riscv/bin:"* ]]; then
    export PATH=$PATH:/opt/riscv/bin
    echo "PATH successfully added to your systems!: $PATH"
else
    echo "PATH already exists: $PATH"
fi

echo "Current environment variables:"
echo "LD_LIBRARY_PATH=$LD_LIBRARY_PATH"
echo "PATH=$PATH"
