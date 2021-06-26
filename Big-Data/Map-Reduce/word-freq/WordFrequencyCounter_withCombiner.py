"""
python WordFrequencyCounter_withCombiner.py Book
"""

from mrjob.job import MRJob
import re

WORD_REG_EXP = re.compile(r"[\w']+")


# Count of frequncy of the words
class MRWordFrequencyCounter_withCombiner(MRJob):

    def mapper(self, key, line:str) -> (str, int):
        #words = line.split(' ')            # spilts words based on space
        words = WORD_REG_EXP.findall(line)  # identifies only word character(w)
        for word in words:
            yield word.lower(), 1

    def combiner(self, word:str, occurences:tuple) -> (str, int):
        yield word, sum(occurences)

    def reducer(self, word:str, occurences:tuple) -> (str, int):
        yield word, sum(occurences)


if __name__ == '__main__':
    MRWordFrequencyCounter_withCombiner.run()
