import requests
import lxml.html

u  = "https://ringzer0team.com/challenges/13"
#xp = '/html/body/div[2]/div/div[2]/div/text()[2]'
xp2= '/html/body/div[2]/div/div[2]/div'
xp3= '/html/body/div[2]/div/div[2]'


def parse_html_by_xpath(html_str, p_xpath):
    html_xpathed = lxml.html.document_fromstring(html_str).xpath(p_xpath)
    return html_xpathed



if __name__ == "__main__":
    htm = requests.get(u).content
    #print htm
    print parse_html_by_xpath(htm, xp3)
