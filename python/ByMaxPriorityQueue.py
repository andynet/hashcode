from queue import PriorityQueue
import itertools

class ByMaxPriorityQueue(PriorityQueue):

    tiebreaker = itertools.count()


    def put(self, val, index, *args, **kwargs):
        if index >= len(val[1]):
            raise ValueError('Incorrent index')
        super().put((-val[0].iat[index], next(self.tiebreaker), (index, val)), *args, **kwargs)

    def get(self, *args, **kwargs):
        """
        return tuple (val,index)
        """
        key, tie, val = super().get(*args, **kwargs)
        return val
