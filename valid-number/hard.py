import re

class Solution:
    def isNumber(self, s: str) -> bool:
        engine = re.compile(r"^[+-]?((\d+\.?\d*)|(\d*\.?\d+))([eE][+-]?\d+)?$")
        res = engine.match(s.strip(" "))
        return True if res else False
