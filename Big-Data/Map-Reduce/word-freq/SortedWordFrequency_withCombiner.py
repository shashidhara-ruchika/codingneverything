"""
python SortedWordFrequency.py Book
"""

from mrjob.job import MRJob
from mrjob.job import MRStep
import re

WORD_REG_EXP = re.compile(r"[\w']+")


# Frequncy of the words sorted by num of occurences(freq)
class MRSortedWordFrequency(MRJob):

    def steps(self):
        return [
                MRStep(
                        mapper   = self.mapper_get_words,
                        combiner = self.reducer_get_word_freq,
                        reducer  = self.reducer_get_word_freq
                        ),
                MRStep(
                        mapper   = self.mapper_make_freq_as_key,
                        reducer  = self.reducer_get_sorted_word_freq
                        )
                ]

    def mapper_get_words(self, key, line:str) -> (str, int):
        #words = line.split(' ')            # spilts words based on space
        words = WORD_REG_EXP.findall(line)  # identifies only word character(w)
        for word in words:
            yield word.lower(), 1

    def reducer_get_word_freq(self, word:str, occurences:tuple) -> (str, int):
        yield word, sum(occurences)

    # swap word freq & word as key & value
    def mapper_make_freq_as_key(self, word:str, word_freq:str) -> (str, str):
        yield '%04d'%int(word_freq), word   # word freq is padded with 0 infront for 4 digits

    def reducer_get_sorted_word_freq(self, word_freq:str, word:tuple) -> (str, str):
        for wi in word:
            yield wi, int(word_freq)


if __name__ == '__main__':
    MRSortedWordFrequency.run()
