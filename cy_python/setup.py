from setuptools import setup
from setuptools.extension import Extension
from Cython.Distutils import build_ext
from Cython.Build import cythonize
import numpy as np

ext_modules = cythonize(Extension("cppy_load",
    sources= ["cppy_load.pyx","../load.cpp"],
    include_dirs=[np.get_include()],
    language="c++",
    extra_compile_args=["-O3","--std=c++14"]
    ))


setup(
  name = 'load',
  cmdclass = {'build_ext': build_ext},
  ext_modules = ext_modules
)
