/* alert tcp $EXTERNAL_NET $HTTP_PORTS -> $HOME_NET any (msg:"WEB-CLIENT Malformed BMP dimensions arbitrary code execution attempt"; flow:to_client,established; content:"BM"; depth:300; content:"|28 00 00 00|"; distance:12; within:4; metadata:policy balanced-ips drop, policy security-ips drop, service http; classtype:attempted-user; reference:cve,2009-2989; sid:16222;)
 *
 *
 * Use at your own risk.
 *
 * Copyright (C) 2005-2008 Sourcefire, Inc.
 * 
 * This file is autogenerated via rules2c, by Brian Caswell <bmc@sourcefire.com>
 */


#include "sf_snort_plugin_api.h"
#include "sf_snort_packet.h"
#include <math.h>

//#define DEBUG
#ifdef DEBUG
#define DEBUG_SO(code) code
#else
#define DEBUG_SO(code)
#endif


/* declare detection functions */
int rule16222eval(void *p);

/* declare rule data structures */
/* precompile the stuff that needs pre-compiled */
/* flow:established, to_client; */
static FlowFlags rule16222flow0 = 
{
    FLOW_ESTABLISHED|FLOW_TO_CLIENT
};

static RuleOption rule16222option0 =
{
    OPTION_TYPE_FLOWFLAGS,
    {
        &rule16222flow0
    }
};
// content:"BM", depth 500; 
static ContentInfo rule16222content1 = 
{
    (uint8_t *) "BM", /* pattern (now in snort content format) */
    300, /* depth */
    0, /* offset */
    CONTENT_RELATIVE|CONTENT_BUF_NORMALIZED, /* flags */
    NULL, /* holder for boyer/moore PTR */
    NULL, /* more holder info - byteform */
    0, /* byteform length */
    0 /* increment length*/
};

static RuleOption rule16222option1 = 
{
    OPTION_TYPE_CONTENT,
    {
        &rule16222content1
    }
};
#ifndef CONTENT_FAST_PATTERN
#define CONTENT_FAST_PATTERN 0
#endif
// content:"|28 00 00 00|", offset 12, depth 4, relative, fast_pattern; 
static ContentInfo rule16222content2 = 
{
    (uint8_t *) "|28 00 00 00|", /* pattern (now in snort content format) */
    4, /* depth */
    12, /* offset */
    CONTENT_RELATIVE|CONTENT_FAST_PATTERN|CONTENT_BUF_NORMALIZED, /* flags */
    NULL, /* holder for boyer/moore PTR */
    NULL, /* more holder info - byteform */
    0, /* byteform length */
    0 /* increment length*/
};

static RuleOption rule16222option2 = 
{
    OPTION_TYPE_CONTENT,
    {
        &rule16222content2
    }
};

/* flowbits:isset "file.bmp"; */
static FlowBitsInfo rule16222flowbits3 =
{
    "file.bmp",
    FLOWBIT_ISSET,
    0,
};

static RuleOption rule16222option3 =
{
    OPTION_TYPE_FLOWBIT,
    {
        &rule16222flowbits3
    }
};

/* references for sid 16222 */
/* reference: cve "2009-2989"; */
static RuleReference rule16222ref1 = 
{
    "cve", /* type */
    "2009-2989" /* value */
};
/* reference:url,www.adobe.com/support/security/bulletins/apsb09-16.html; */
static RuleReference rule16222ref2 =
{
    "url", /* type */
    "www.adobe.com/support/security/bulletins/apsb09-16.html" /* value */
};

/* reference: cve "2009-3678"; */
static RuleReference rule16222ref3 =
{
    "cve", /* type */
    "2009-3678" /* value */
};

/* reference:url,www.microsoft.com/technet/security/advisory/2028859.mspx; */
static RuleReference rule16222ref4 =
{
    "url", /* type */
    "www.microsoft.com/technet/security/advisory/2028859.mspx" /* value */
};

/* reference:url,technet.microsoft.com/en-us/security/bulletin/MS10-043; */
static RuleReference rule16222ref5 =
{
    "url", /* type */
    "technet.microsoft.com/en-us/security/bulletin/MS10-043" /* value */
};

/* reference:cve,2013-3259; */
static RuleReference rule16222ref6 =
{
    "cve", /* type */
    "2013-3259" /* value */
};

static RuleReference *rule16222refs[] =
{
    &rule16222ref1,
    &rule16222ref2,
    &rule16222ref3,
    &rule16222ref4,
    &rule16222ref5,
    &rule16222ref6,
    NULL
};
/* metadata for sid 16222 */
/* metadata:service http, policy balanced-ips drop, policy security-ips drop; */
//static RuleMetaData rule16222service1 = 
//{
//    "service http"
//};
//
//
//static RuleMetaData rule16222policy1 = 
//{
//    "policy balanced-ips drop"
//};
//
//static RuleMetaData rule16222policy2 = 
//{
//    "policy security-ips drop"
//};


static RuleMetaData *rule16222metadata[] =
{
//    &rule16222service1,
//    &rule16222policy1,
//    &rule16222policy2,
    NULL
};

RuleOption *rule16222options[] =
{
    &rule16222option0,
    &rule16222option1,
    &rule16222option2,
    &rule16222option3,
    NULL
};

Rule rule16222 = {
   
   /* rule header, akin to => tcp any any -> any any               */{
       IPPROTO_TCP, /* proto */
       "$EXTERNAL_NET", /* SRCIP     */
       "$HTTP_PORTS", /* SRCPORT   */
   
       0, /* DIRECTION */
       "$HOME_NET", /* DSTIP     */
   
       "any", /* DSTPORT   */
   },
   /* metadata */
   { 
       3,  /* genid */
       16222, /* sigid */
       11, /* revision */
   
       "attempted-user", /* classification */
       0,  /* hardcoded priority XXX NOT PROVIDED BY GRAMMAR YET! */
       "FILE-IMAGE Malformed BMP dimensions arbitrary code execution attempt",     /* message */
       rule16222refs /* ptr to references */
       ,rule16222metadata
   },
   rule16222options, /* ptr to rule options */
   &rule16222eval, /* use the built in detection function */
   0 /* am I initialized yet? */
};


/* detection functions */
int rule16222eval(void *p) {
    const uint8_t *cursor_normal = 0;
    SFSnortPacket *sp = (SFSnortPacket *) p;

    const uint8_t *end_of_payload;
    uint32_t width;
    uint32_t height;
    uint32_t size;
    uint32_t imagesize;

    double result;
    uint16_t bitsperpixel;

    if(sp == NULL)
        return RULE_NOMATCH;

    if(sp->payload == NULL)
        return RULE_NOMATCH;
    
    // flow:established, to_client;
    if (checkFlow(p, rule16222options[0]->option_u.flowFlags) > 0 ) {
        // flowbits:isset "file.bmp";
        if (processFlowbits(p, rule16222options[3]->option_u.flowBit) > 0) {

            // First match is relative, so must initialize the cursor
            if(getBuffer(p, CONTENT_BUF_NORMALIZED, &cursor_normal, &end_of_payload) <= 0)
               return RULE_NOMATCH;

            // content:"BM", depth 300;
            // depth with while() so we can skip over any "BM" in HTTP headers
            while (contentMatch(p, rule16222options[1]->option_u.content, &cursor_normal) > 0) {
                // content:"|28 00 00 00|", offset 12, depth 4, relative, fast_pattern;
                if (contentMatch(p, rule16222options[2]->option_u.content, &cursor_normal) > 0) {
   
                    //width and height are the next 8 bytes, cut out if packet ends
                    if (cursor_normal + 8 > end_of_payload)
                        return RULE_NOMATCH;
   
                    //Extact width and height values
                    //Exit if either value is 0
                    width = *cursor_normal++;
                    width |= *cursor_normal++ << 8;
                    width |= *cursor_normal++ << 16;
                    width |= *cursor_normal++ << 24;
    
                    DEBUG_SO(printf("width=0x%08x (%d)\n", width, width));
    
                    if (width == 0)
                        return RULE_NOMATCH;
    
                    height = *cursor_normal++;
                    height |= *cursor_normal++ << 8;
                    height |= *cursor_normal++ << 16;
                    height |= *cursor_normal << 24;
    
                    DEBUG_SO(printf("height=0x%08x (%d)\n", height, height));
    
                    if (height == 0)
                        return RULE_NOMATCH;
    
                    if (cursor_normal + 13 > end_of_payload)
                        return RULE_NOMATCH;

                    cursor_normal += 9;

                    imagesize = *cursor_normal++;
                    imagesize |= *cursor_normal++ << 8;
                    imagesize |= *cursor_normal++ << 16;
                    imagesize |= *cursor_normal << 24;

                    DEBUG_SO(printf("imagesize=0x%08x (%d)\n", imagesize, imagesize));

                    //Extract size value, which is right after the BM file signature
                    //Doing subtraction on the cursor_normal must yield the right data
                    //because cursor is bound by the initial relative content matches
                    cursor_normal -= 35;
    
                    size = *cursor_normal++;
                    size |= *cursor_normal++ << 8;
                    size |= *cursor_normal++ << 16;
                    size |= *cursor_normal << 24;
    
                    DEBUG_SO(printf("size=0x%08x (%d)\n", size, size));
    
                    //Match immediately if size is less than either height or width
                    if (width > size || height > size)
                        return RULE_MATCH;
    
                    //Need to make sure there is enough data left to extract bitsperpixel
                    //If no, fail. If yes, extract.
                    if (cursor_normal + 25 > end_of_payload)
                        return RULE_NOMATCH;

                    cursor_normal += 23;
    
                    bitsperpixel = *cursor_normal++;
                    bitsperpixel |= *cursor_normal << 8;
    
                    DEBUG_SO(printf("bitsperpixel=0x%04x (%d)\n", bitsperpixel, bitsperpixel));
    
                    //Calculate result (expected size) and fire if there is:
                    //    1) An overflow, since the size field is only 4 bytes long
                    //    2) The expected result does not overflow but is still larger
                    //       than the size field. 
                    
                    //result is a double, max value outstrips the upper bound on the multiplication
                    //of two DWORDS and a WORD. Will not overflow. Using ceil function to round
                    //up to the next unit, which, together with padding, should give us the
                    //exact number of bytes to expect in the file.
                    result = ceil((double)width * (double)height * (double)bitsperpixel / 8);

                    DEBUG_SO(printf("result=0x%016llx\n", (unsigned long long)result));
                    
                    //Size is a DWORD, so checking result > size is sufficient. If result overflows
                    //then it will still be bigger than the max value of size.
                    //Ensuring that imagesize is not 0, because BMPs with a compression method of 0
                    //declare their imagesize as 0. We may eventually wish to validate the
                    //declared compression method as well, but why take the extra steps unless we
                    //have to?
                    if((result > size) || ((imagesize != 0) && (result > imagesize)))
                        return RULE_MATCH;
                }
            }
        }
    }
    return RULE_NOMATCH;
}

/*
Rule *rules[] = {
    &rule16222,
    NULL
};
*/


