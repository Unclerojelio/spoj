import sys



for line in sys.stdin:

    line = line.strip()

    if line <> "42":

        print line

    else:

        break
