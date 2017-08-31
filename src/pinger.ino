bool lastPingState;
void initPinger()
{
    lastPingState = ping();
}
bool ping()
{
    return Ping.ping(mlIp, 3);
}

void intervalPing()
{
    bool currentState = ping();
    if (lastPingState != currentState)
    {
        if (ping())
        {
            sendMessage(GROUIP, "ml is online now");
        }
        else
        {
            sendMessage(GROUIP, "ml is ofline now");
        }
        lastPingState = currentState;
    }
}