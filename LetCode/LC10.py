#!/usr/bin/env python
# -*- coding: utf-8 -*-
# encoding: utf-8
# author: myron


import codecs


class Solution(object):
    def string_pattern_match(self, text, pattern):
        if not pattern:
            return not text
        first_match = bool(text) and pattern[0] in {text[0], '.'}
        if len(pattern) >= 2 and pattern[1] == '*':
            return self.string_pattern_match(text, pattern[2:]) \
                   or first_match and self.string_pattern_match(text[1:], pattern)
        else:
            return first_match and self.string_pattern_match(text[1:], pattern[1:])


def main():
    test = Solution()
    is_true = test.string_pattern_match("abcdf", "abc.*f")
    print(is_true)


# 函数入口
if __name__ == "__main__":
    main()