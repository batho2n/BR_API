#!/usr/bin/python
# -*- coding: utf-8 -*-
#
# @file         matFileIO.py
# @breif        Save HRTF filters from .mat file for using C/C++
# @date         2017-03-29
# @author       batho2n@gmail.com
#
# Copyroght (C) 2017 batho2n
# All Right Reserved
#

from __future__ import print_function

import os
import sys
import numpy as np
import scipy.io as sio
import getopt
import string

def usage(argv):
    print('')
    print('Usage: %s -i filename.mat -o filename.h' % argv)
    print('[options]')
    print('     -h  : usage')
    print('     -i  : input file name [mat]')
    print('     -o  : output file name [h]')
    print('')
    return

def mymain(inFname, outFname):
    mat_HRIR = sio.loadmat(inFname)

    return

if __name__ == '__main__':
  
    inFname = ''
    outFname = ''
    if len(sys.argv) <= 1:
        usage(sys.argv[0])
        sys.exit(1)
    try:
        opts, args = getopt.getopt(sys.argv[1:], 'i:h:o:')
    except getopt.GetoptError as err:
        print (str(err))
        usage(sys.argv[0])
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            usage(prog)
            sys.exit(0)
        elif opt == '-i':
            inFname = arg
        elif opt == '-o':
            outFname = arg

    if inFname == '':
        print('[ERR]Input file name is null')
        sys.exit(3)
    if outFname == '':
        print('[ERR]Output file name is null')
        sys.exit(4)

    in_token = inFname.split('.')
    if in_token[-1] != 'mat':
        print('[ERR] Input file is not mat file:', in_token)
        sys.exit(5)
    out_token= outFname.split('.')
    if out_token[-1] != 'h':
        print('[ERR] Oputut file is not h file:', out_token)
        sys.exit(6)
    
    print('%s --->' % inFname, end=' ')
    mymain(inFname, outFname)
    print('%s' % outFname)
    sys.exit(0)
