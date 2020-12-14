import sys
import numpy as np
import imagezmq
import cv2 as cv

imageHub = imagezmq.ImageHub()

## start looping over all the frames
while True:
	# receive RPi name and frame from the RPi and acknowledge
	# the receipt
	rpiName, frame = imageHub.recv_image()
	cv.imshow("cuong", frame) # 1 window for each RPi

	cv.waitKey(1)
	imageHub.send_reply(b'OK')

	if cv.waitKey(1) == ord('q'):
		break

# When everything done, release the capture
cap.release()
cv.destroyAllWindows()

