"""
python MaxTempByLoc.py 1800.csv
"""

from mrjob.job import MRJob


# Maximum Temperature by Location
class MRMaxTempByLoc(MRJob):

    def convertDegCtoDegF(self, tenth_of_deg_c: str) -> float:
        return ((float(tenth_of_deg_c) / 10.0) * 1.8) + 32.0

    def mapper(self, key, line:str) -> (str, int):
        (
            weather_station_id,
            date,               # yyyymmdd
            type_of_reading,
            tenth_of_deg_c,     # 10th of deg C (i.e. -75 deg C means -7.5 deg C)
            attribute1,
            attribute2,
            attribute3,
            attribute4
        ) = line.split(',')
        if (type_of_reading == "TMAX"):
            yield weather_station_id, self.convertDegCtoDegF(tenth_of_deg_c)

    def combiner(self, weather_station_id:str, deg_c:tuple) -> (str, int):
        yield weather_station_id, max(deg_c)

    def reducer(self, weather_station_id:str, deg_c:tuple) -> (str, int):
        yield weather_station_id, max(deg_c)


if __name__ == '__main__':
    MRMaxTempByLoc.run()
