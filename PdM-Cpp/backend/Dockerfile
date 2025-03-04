# Stage 1: Build the application
FROM ubuntu:20.04 AS builder

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
      cmake \
      build-essential \
      libpthread-stubs0-dev \
      && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy the project files; use .dockerignore to skip local build artifacts.
COPY . .

# Remove any previous build directory and build the project.
RUN rm -rf build && mkdir build && cd build && \
    cmake .. && \
    cmake --build . --config Release

# Stage 2: Runtime container
FROM ubuntu:20.04

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y libstdc++6 && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Adjust the path if your executable is in a Debug/Release folder.
COPY --from=builder /app/build/PredictiveMaintenance /usr/local/bin/PredictiveMaintenance

# Expose port 8080 if your backend provides an API.
EXPOSE 8080

CMD ["/usr/local/bin/PredictiveMaintenance"]
