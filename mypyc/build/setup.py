from setuptools import setup
from mypyc.build import mypycify

setup(name='mypyc_output',
      ext_modules=mypycify(['lcs_with_mypyc.py'], opt_level="3", debug_level="1", strict_dunder_typing=False),
)
