# The xxxxxxx in the sender and receiver email information should be replaced with a throw away
# email account created by the user due to the lack of encryption. emaials should be in the form of
# example@domain.com
# 
#improvements to make:
# Save encrypted sender email and sender password somewhere so it isnt recquired for input everytime
# More email type support

import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders

sender_email = "xxxxxxxxx"
sender_pass = "xxxxxxxx"
receiver_email = "xxxxxxx"

domain = sender_email.split('@', 1)[1]
if(domain == 'gmail.com'):
    smtServer = smtplib.SMTP('smtp.gmail.com', 587)
elif(domain == 'outlook.com' or domain == '@hotmail.com'):
    smtServer = smtplib.SMTP('smtp-mail.outlook.com', 587)
elif(domain == 'yahoo.com'):
    smtServer = smtplib.SMTP('smtp.mail.yahoo.com', 587)
else:
    print("Invalid or Non-compatible sender email domain")

msg = MIMEMultipart()
msg['From'] = sender_email
msg['To'] = receiver_email
msg['Subject'] = 'Weekly Alert Log'
filename = "alert"
attachment = open("/var/log/snort/alert", "rb")
p = MIMEBase('application', 'octet-stream')
p.set_payload((attachment).read())
encoders.encode_base64(p)
p.add_header('Content-Disposition', "attachment; filename= %s" % filename)
msg.attach(p)
smtServer.ehlo()
smtServer.starttls()
smtServer.login(sender_email, sender_pass)
text = msg.as_string()
smtServer.sendmail(sender_email, receiver_email, text)
