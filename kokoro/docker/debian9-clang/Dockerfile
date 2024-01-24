# Dockerfile for a Debian build container with a recent Clang installed.
# Rebuild and upload with
#   podman build --format docker -t gcr.io/zynamics-build/debian9-clang:latest .
#   podman push gcr.io/zynamics-build/debian9-clang:latest
#
# You may need to login to the Google cloud project first:
#   gcloud auth login
#   gcloud auth print-access-token | \
#     podman login -u oauth2accesstoken --password-stdin gcr.io

FROM debian:buster

ENV TZ=Europe/Zurich\
    DEBIAN_FRONTEND=noninteractive
SHELL ["/bin/bash", "-c"]
ADD llvm-snapshot.asc /etc/apt/trusted.gpg.d/
RUN chmod 644 /etc/apt/trusted.gpg.d/llvm-snapshot.asc && \
    apt-get update && \
    apt-get install -qy --no-install-recommends ca-certificates && \
    echo 'deb https://apt.llvm.org/buster/ llvm-toolchain-buster-15 main' > \
        /etc/apt/sources.list.d/llvm-toolchain.list && \
    echo 'APT::Default-Release "buster";' > \
        /etc/apt/apt.conf.d/00targetrelease && \
    apt-get update && \
    apt-get install -qy --no-install-recommends \
        clang-15 \
        git \
        gnupg \
        libc++-15-dev \
        libc++abi-15-dev \
        libstdc++-8-dev \
        ninja-build \
        wget \
    && \
    # Make clang 15 the default in auto mode
    update-alternatives --install /usr/bin/cc cc /usr/bin/clang-15 150 && \
    update-alternatives --install /usr/bin/cpp cpp /usr/bin/clang-cpp-15 150 && \
    update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++-15 150 && \
    # Clean up to save space
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* && \
    # Suppress warnings about detached HEAD
    git config --global advice.detachedHead false && \
    git config --global submodule.recurse true && \
    # Install CMake
    [[ "$(wget -qO - \
            https://github.com/Kitware/CMake/releases/download/v3.25.2/cmake-3.25.2-linux-x86_64.sh | \
            tee cmake.sh | sha256sum | cut '-d ' -f1)" == \
        "4d98de8d605da676e71a889dd94f80c76abb377fade2f21e3510e62ece1e1ada" ]] && \
    sh cmake.sh --prefix=/usr/local --exclude-subdir --skip-license && \
    rm cmake.sh
