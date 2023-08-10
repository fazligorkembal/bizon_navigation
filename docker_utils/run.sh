#!/bin/bash
xhost +

docker run -it --rm \
--privileged  \
--net=host \
-e NVIDIA_VISIBLE_DEVICES=all \
-e NVIDIA_DRIVER_CAPABILITIES=all \
-e DISPLAY=$DISPLAY \
-e QT_X11_NO_MITSHM=1 \
-v /tmp/.X11-unix:/tmp/.X11-unix \
--gpus all test:latest \
bash

