'''
Step 1: in cmd python setup.py install
Step 2: python setup.py py2exe
step 3: copy: GeRSDeMo_csv.exe into the dist folder

'''


from distutils.core import setup
import os
import sys
import py2exe
def dependencies_for_myprogram():
    from scipy.special.cython_special import _stats
    
#origIsSystemDLL = py2exe.build_exe.isSystemDLL # save the orginal before we edit it
#def isSystemDLL(pathname):
    # checks if the freetype and ogg dll files are being included
#    if os.path.basename(pathname).lower() in ("libfreetype-6.dll", "libogg-0.dll", "sdl_ttf.dll"):
#            return 0
#    return origIsSystemDLL(pathname) # return the orginal function
#py2exe.build_exe.isSystemDLL = isSystemDLL # override the default function with this one
#setup(options = {"py2exe": {"dll_excludes": ["MSVCP90.dll"]}},console=['Gui_Example5.py','pygbutton.py'])
setup(console=['Resource_Model.py'],
      options = {'py2exe':{
          r'includes':[r'scipy.stats._stats',
                       r'scipy.stats._stats',
                       r'scipy.special.cython_special',
                       r'lxml',
                       r'lxml.etree',
                       r'lxml._elementpath',
                       r'matplotlib',
                       r'matplotlib.backends',
                       r'matplotlib.backends.backend_ps']
          }}

      )

