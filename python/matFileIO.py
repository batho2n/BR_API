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

def write_HRIR_degree (f, l_elev_v, l_azim_v):
    l_elev_v = (l_elev_v + 45)/15

    cnt = np.zeros(max(l_elev_v)+1)
    for i in range(len(l_elev_v)):
        cnt[l_elev_v[i]] += 1

    arr = np.zeros(len(cnt)+1)
    for i in range(1, len(arr)):
        arr[i] = arr[i-1] + cnt[i-1]
    
    f.write('int ele[%d] = {' %len(arr))
    f.write(str(int(arr[0])))
    for i in range(1, len(arr)):
        f.write(', ' + str(int(arr[i])))
    f.write('};')
    f.write('\n')
    f.write('int azi[%d] = {' %len(l_azim_v))
    f.write(str(int(l_azim_v[0])))
    for i in range(1,len(l_azim_v)):
        f.write(', ' + str(int(l_azim_v[i])))

    f.write('};')

    return

def mymain(inFname, outFname):
    mat_HRIR = sio.loadmat(inFname)
    l_eq_struct = mat_HRIR['l_eq_hrir_S'] 
    val = l_eq_struct[0,0]
    l_elev_v = val['elev_v']
    l_azim_v = val['azim_v']
    l_type_s = val['type_s']
    l_sampling_hz = val['sampling_hz']
    l_content_m = val['content_m']
 
    r_eq_struct = mat_HRIR['r_eq_hrir_S'] 
    val = r_eq_struct[0,0]
    r_elev_v = val['elev_v']
    r_azim_v = val['azim_v']
    r_type_s = val['type_s']
    r_sampling_hz = val['sampling_hz']
    r_content_m = val['content_m']
    
    #l_eq_hrir_S = mat_HRIR.get('l_eq_hrir_S')
    #fs = l_eq_hrir_S.get('sampling_hz')

    f = open(outFname,'w')
    write_HRIR_degree (f, l_elev_v, l_azim_v)
    f.close()
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
    
#   print('%s --->' % inFname, end=' ')
    mymain(inFname, outFname)
#   print('%s' % outFname)
    sys.exit(0)
