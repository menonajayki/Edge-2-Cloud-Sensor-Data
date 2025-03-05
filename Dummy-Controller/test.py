import dummy_microscope

print("Test script is running...")

def main():
    microscope = dummy_microscope.DummyMicroscope()
    
    if microscope.initialize():
        microscope.set_power_level(5.0)
        image_file = microscope.acquire_image(1024, 768)
        print(f"Image acquired and saved as {image_file}")
        microscope.shutdown()
    else:
        print("Initialization failed!")

if __name__ == "__main__":
    main()
