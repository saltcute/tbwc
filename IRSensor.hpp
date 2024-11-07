#define DISTANCE_OUTPUT 0

bool isIRDetected()
{
    int rawReading = analogRead(DISTANCE_OUTPUT);
    return rawReading < 512;
}
