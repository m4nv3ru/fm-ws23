#!/bin/bash

# Activate the virtual environment
# Replace './venv' with the path to your virtual environment if it's different
source ./venv/bin/activate

# Launch Jupyter Notebook with the name "fm"

echo "http://localhost:8888/notebooks/fm.ipynb"
jupyter notebook --port=8888 --no-browser --NotebookApp.token='' --NotebookApp.password='' --NotebookApp.disable_check_xsrf=True

# Deactivate the virtual environment
deactivate