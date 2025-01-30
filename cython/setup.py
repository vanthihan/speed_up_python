from Cython.Build import cythonize
from setuptools import setup

setup(
    ext_modules=cythonize(
        ["lcs_module.py", "lcs_modulex.pyx"], 
        compiler_directives={'language_level': 3}
    )
)
