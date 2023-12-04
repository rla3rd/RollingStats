import pandas as pd
import numpy as np

__version__ = '0.3.1'

np.seterr(divide='ignore', invalid='ignore')


class RollingStats(object):
    def __init__(self, series, period, mode='sma'):
        s = np.array(series)
        while len(s) < period:
            s = np.concatenate(([0], s))

        if mode == 'ewma':
            self.mean = np.array(
                pd.Series(s).ewm(
                    span=period, min_periods=period).mean().tolist())
            self.stddev = np.array(
                pd.Series(s).ewm(
                    span=period, min_periods=period).std().tolist())
            self.variance = self.stddev ** 2
            self.sum = np.array(pd.Series(s).rolling(period).sum())
        else:
            self.mean = np.mean(self._rolling_period(s, period), -1)
            self.variance = np.var(self._rolling_period(s, period), -1)
            self.stddev = np.std(self._rolling_period(s, period), -1)
            self.sum = np.sum(self._rolling_period(s, period), -1)

            while len(self.mean) < len(s):
                self.mean = np.concatenate(([0], self.mean))
                self.sum = np.concatenate(([0], self.sum))
                self.variance = np.concatenate(([0], self.variance))
                self.stddev = np.concatenate(([0], self.stddev))

        self.zscore = np.divide((s - self.mean), self.stddev)
        np.nan_to_num(self.zscore, copy=False, nan=0, posinf=0, neginf=0)

    def _rolling_period(self, a, window):
        shape = a.shape[:-1] + (a.shape[-1] - window + 1, window)
        strides = a.strides + (a.strides[-1],)
        elements = np.lib.stride_tricks.as_strided(
            a, shape=shape, strides=strides)
        return elements
