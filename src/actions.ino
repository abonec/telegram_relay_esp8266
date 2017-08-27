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