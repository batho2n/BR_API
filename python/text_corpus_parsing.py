#!/usr/bin/python
# -*- coding: utf-8 -*-
#
# @file         text_corpus_parsing.py
# @breif        file separate by content, template, 기타
# @date         2017-03-228
# @author       batho2n@sk.com
#
# Copyroght (C) 2017 SKT
# All Right Reserved
#

from __future__ import print_function

import os
import sys
import numpy as np
import getopt
import string

def usage(prog):
    print('')
    print('Usage: %s -i filename.txt' % prog)
    print('')

def write_file(f,line):
    print(line)    

def parse_txt(fname):
    dirname = fname.split('.')
    dirname = dirname[0] + '/'
    print("Directory Name: %s" % dirname)    
    if not os.path.isdir(dirname):
        os.mkdir(dirname)
    f = open(fname,'r')
    lines = f.readlines()
    f.close()


    num_content = 0
    num_template= 0
    num_chitchat= 0

    for line in lines:
        if line.find('content') != -1:
            num_content += 1
        elif line.find('template') != -1:
            num_template += 1
        elif line.find('기타') != -1:
            num_chitchat += 1

    if num_template > 1:
        print('[ERR] there is over 2 temaplate  titles')
    if num_chitchat > 1:
        print('[ERR] there is over 2 chitchat titles')
    num = 0
    write_flag = 0

    while num < len(lines):
        line = lines[num]
        if line != "\n":
            line = line.replace("\n","")
            if line.find('content') != -1:
                if write_flag == 1:
                    f.close()
                    write_flag = 0
                start = line.index('(') + 1
                end = line.index('/')
                outfname = dirname +line[start:end] + '.txt'
                if write_flag == 0:
                    f = open(outfname,'w')
                    write_flag = 1
                
                print(outfname)
            elif line.find('template') != -1:
                if write_flag == 1:
                    f.close()
                    write_flag = 0
                outfname = dirname + '템플릿.txt'
                if write_flag == 0:
                    f = open(outfname,'w')
                    write_flag = 1
                print(outfname)
            elif line.find('기타') != -1:
                if write_flag == 1:
                    f.close()
                    write_flag = 0
                outfname = dirname + '상용구.txt'
                if write_flag == 0:
                    f = open(outfname,'w')
                    write_flag = 1
                print(outfname)
            else:
                line = line + "\n"
                f.write(line)
        num += 1

    if write_flag == 1:
        f.close()

if __name__ == '__main__':
    prog = 'corpus_parsing.py'
    if len(sys.argv[0]) <= 1:
        usage(sys.argv[0])
        sys.exit(0)

    try:
        opts, args = getopt.getopt(sys.argv[1:], 'i:h')
    except getopt.GetoptError as err:
        print (str(err))
        usage(sys.argv[0])
        sys.exit(1)
    
    fname = ''
    for opt, arg in opts:
        if opt == '-h':
            usage(prog)
            sys.exit(0)
        elif opt == '-i':
            fname = arg

    print('Input fine name: %s' % fname)
    parse_txt(fname)
