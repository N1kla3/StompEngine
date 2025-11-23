import os
import argparse
import subprocess
import sys
import errno
import shutil

platform_map = {"linux": "linux", "win32": "windows"}


def detect_build_preset(build_type: str):
    platform_prefix = platform_map.get(sys.platform, "None")
    build_type_postfix = build_type

    return "-".join([platform_prefix, build_type_postfix])
    # TODO editor build


def get_compilation_json(build_path: str):
    compilation_json_name = "compile_commands.json"
    for root, _, files in os.walk(build_path):
        if compilation_json_name in files:
            return os.path.join(root, compilation_json_name)
    return None


def run_and_stream_output(command):
    """
    Runs a shell command and streams its stdout and stderr live to the console.
    """
    process = subprocess.Popen(
        command,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,  # Redirect stderr to stdout for combined output
        text=True,  # Decode output as text
        bufsize=1,  # Line-buffered output
    )

    while True:
        line = process.stdout.readline()
        if not line and process.poll() is not None:
            break  # Process finished and no more output
        if line:
            sys.stdout.write(line)
            sys.stdout.flush()  # Ensure immediate display

    return process.returncode


def build(path: str, fresh_build: bool):
    if not os.path.exists(path):
        print(f"Folder not found, creating it {path}")
        os.mkdir(path)
    elif fresh_build == True:
        print("Removing build directory")
        shutil.rmtree(path)
        os.mkdir(path)

    result = run_and_stream_output(["cmake", ".", "--preset", path])

    if result == 0:
        build_res = run_and_stream_output(["cmake", "--build", path])
        print(f"Compilation Exit with Code {build_res}")
    else:
        print(f"Cmake finished with not zero exit code: {result}")
        return
    if fresh_build:
        copy_compilation(path)


def copy_compilation(path: str):
    target = get_compilation_json(path)
    if target != None:
        print("Copying compilation json")
        shutil.copy(target, ".")


# Should be run from the root directory of git repo
if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--build", type=str, default="debug", choices=["debug", "release"]
    )
    parser.add_argument(
        "--fresh",
        action="store_true",
        help="Remove build folder and build from scratch",
    )
    args = parser.parse_args()

    preset = detect_build_preset(args.build)
    print(f"Detected preset is :{preset}")
    build(preset, args.fresh)
