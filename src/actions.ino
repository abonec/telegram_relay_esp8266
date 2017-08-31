void pingAction(String chat_id)
{
    if (ping())
    {
        sendMessage(chat_id, "ML is online");
    }
    else
    {
        sendMessage(chat_id, "ML is offline");
    }
}

void turnMLAction(String chat_id)
{
    turnML();
    sendMessage(chat_id, "ML was turned");
    delay(MACHINE_TURN_TIMEOUT);
    pingAction(chat_id);
}

void setIpAction(String chat_id, String ip)
{
    int ipParts[4];
    int partIndex = 0;
    String part = "";
    for (int i = 0; i <= (ip.length()); i++)
    {
        if (ip[i] == '.')
            {
                ipParts[partIndex] = part.toInt();
                part = "";
                partIndex++;
            }
        else
        {
            part.concat(ip[i]);
        }
    }
    ipParts[3] = part.toInt();
    IPAddress addr = IPAddress(ipParts[0], ipParts[1], ipParts[2], ipParts[3]);
    saveIp(ipParts);
}