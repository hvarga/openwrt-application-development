# Based on requirements [1], start from Debian 9.3.
# [1] https://openwrt.org/docs/guide-developer/build-system/install-buildsystem
FROM debian:9.3

LABEL maintainer="hrvoje.varga@gmail.com"
LABEL build="docker build -t hvarga/openwrt-builder ."
LABEL run="docker run -it --rm -v ${PWD}:/home/openwrt/work hvarga/openwrt-builder"

# Install OpenWrt build dependancies listed in the official requirements [1].
RUN apt-get update -q && DEBIAN_FRONTEND=noninteractive apt-get install -qy \
    build-essential \
    libncurses5-dev \
    gawk \
    git \
    subversion \
    libssl-dev \
    gettext \
    zlib1g-dev \
    unzip \
    wget \
    python \
    file

# Install QEMU so that we can run OpenWrt image as a virtualized machine.
RUN DEBIAN_FRONTEND=noninteractive apt-get install -qy qemu

# Install a text editor.
RUN DEBIAN_FRONTEND=noninteractive apt-get install -qy vim

# Cached packages are not needed anymore and they just increase the image size.
# Remove cached packages.
RUN rm -rf /var/lib/apt/lists/*

# Official requirements [1] state that we should do everything as normal user.
# root user or sudo must not be used.
# Add unprivileged user which will be used to build OpenWrt.
RUN useradd openwrt --create-home --uid 1000

# Switch to the unprivileged user and set default working directory.
USER openwrt
WORKDIR /home/openwrt/work

# Configure BASH as an entrypoint.
ENTRYPOINT ["bash"]