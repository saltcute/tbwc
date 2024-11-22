#define DISTANCE_OUTPUT 0

/**
 * Check if IR sensor is active.
 * @return True if IR sensor is active.
 */
bool isIRDetected()
{
    int rawReading = analogRead(DISTANCE_OUTPUT);
    return rawReading < 512;
}
