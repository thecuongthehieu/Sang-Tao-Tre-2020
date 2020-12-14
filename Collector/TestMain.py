import cv2
import numpy as np
import os, sys , time
import Shuttlecocks as shu
import threading

def main():

    shuttle = shu.SHU()
    while True:
        frame, rect = shuttle.find()
        shuttle.show(frame, rect)

if __name__ == "__main__":
    main()