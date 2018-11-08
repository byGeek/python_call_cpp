from distutils.core import setup, Extension, DEBUG

#more info about setup.py, please ref: https://docs.python.org/3/extending/building.html

sfc_module = Extension('superfastcode', 
                       libraries=['StaticLib1'],  #dependency
                       sources = ['source.cpp'])

setup(name = 'superfastcode', version = '1.0',
    description = 'Python Package with superfastcode C++ extension',
    ext_modules = [sfc_module]
    )