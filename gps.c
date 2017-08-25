/****************************************
* Project name:
	GPS
* Description:
	This code demostrates how to use GPS
* Programmer:
	Pye Sone Aung Myint Htay (Myanmar)
* Version:
	1.0.0
* MCU:
	dsPIC
*******************************************/

char dat_buff, buff[500], buff_1[500];
unsigned int count=0, mode=0, flag_start=0, coma=0, i=0, sub_count=0, flag_star=0, j=0;
unsigned int zero_lat=0, zero_lon=0, zero_sat=0, zero_alt=0, zero_spd_k=0, zero_cog_t=0, zero_op_mode=0, zero_HDOP=0, zero_spd_kph=0;
//data buffers
char lat[10]={48,48,48,48,46,48,48,48,48,48}, lon[11]={48,48,48,48,46,48,48,48,48,48}, alt[6]={48,48,48,48,46,48};
char sep[6]={48,48,48,48,46,48}, no_sat[2]={48, 48}, spd_k[7]={48,48,48,48,48,48,48}, spd_kph[7]={48,48,48,46,48,48,48};
char cog_t[6]={48,48,48,48,46,48}, op_mode, nav_mode, PDOP[5]={48,48,46,48,48}, HDOP[5]={48,48,46,48,48}, VDOP[5]={48,48,46,48,48};

void GNGGA_mode()
{

                    coma=0;
                     for(i=5;coma<2;i++)
                    {
                         if(buff_1[i]== ',')
                             coma++;
                    }

                    for(sub_count=0;coma<3;i++)
                    {
                          if(buff_1[i]== ',')
                          {
                               coma++;
                               if(sub_count==0) zero_lat=1;
                          }
                          else
                          {
                             lat[sub_count]=buff_1[i];
                             sub_count++;
                          }
                    }

                    for(;coma<4;i++)
                    {
                         if(buff_1[i]== ',')
                             coma++;
                    }

                    for(sub_count=0;coma<5;i++)
                    {
                          if(buff_1[i]== ',')
                          {
                             coma++;
                             if(sub_count==0) zero_lon=1;
                          }
                          else
                          {
                             lon[sub_count]=buff_1[i];
                             sub_count++;
                          }
                    }

                    for(;coma<7;i++)
                    {
                         if(buff_1[i]== ',')
                             coma++;

                    }

                    for(sub_count=0;coma<8;i++)
                    {
                          if(buff_1[i]== ',')
                          {
                             coma++;
                             if(sub_count==0) zero_sat=1;
                          }
                          else
                          {
                               no_sat[sub_count]=buff_1[i];
                               sub_count++;
                          }
                    }


                    for(sub_count=0;coma<9;i++)
                    {
                          if(buff_1[i]== ',')
                          {
                             coma++;
                             if(sub_count==0) zero_HDOP=1;
                          }
                          else
                          {
                               HDOP[sub_count]=buff_1[i];
                               sub_count++;
                          }

                    }

                    for(sub_count=0;coma<10;i++)
                    {
                          if(buff_1[i]== ',')
                          {
                             coma++;
                             if(sub_count==0) zero_alt=1;
                          }
                          else
                          {
                              alt[sub_count]=buff_1[i];
                              sub_count++;

                          }

                    }

                    for(sub_count=0;coma<=11;i++)
                    {
                          if(buff_1[i]== ',')
                             coma++;

                    }

                    for(sub_count=0;coma<12;i++)
                    {
                          if(buff_1[i]== ',')
                               coma++;
                                                  else
                                                  {
                                                          sep[sub_count]=buff[i];
                                                          sub_count++;
                                                  }

                    }
                    /*Data output lat*/
                    if(zero_lat==1)
                    {
                         UART2_Write_Text("Lat:");
                         UART2_Write_Text("0000.00000 ");
                         zero_lat=0;
                    }
                    else
                    {
                        UART2_Write_Text("Lat:");
                        for(j=0;j<=9;j++)
                                         UART2_Write(lat[j]);
                        UART2_Write(' ');
                    }
                    /*Data output lon*/
                    if(zero_lon==1)
                    {
                         UART2_Write_Text("Lon:");
                         UART2_Write_Text("00000.00000 ");
                          zero_lon=0;
                    }
                    else
                    {
                        UART2_Write_Text("Lon:");
                        for(j=0;j<=10;j++)
                                          UART2_Write(lon[j]);
                        UART2_Write(' ');
                    }
                    /*Data output No_Sat*/
                    if(zero_sat==1)
                    {
                         UART2_Write_Text("No_Sat:");
                         zero_sat=0;
                         UART2_Write_Text("00 ");

                    }
                    else
                    {
                        UART2_Write_Text("No_Sat:");
                        for(j=0;j<=1;j++)
                                         UART2_Write(no_sat[j]);
                        UART2_Write(' ');
                    }

                      /*Data output HDOP*/
                    if(zero_sat==1)
                    {
                         UART2_Write_Text("HDOP:");
                         zero_sat=0;
                         UART2_Write_Text("00.000 ");
                    }
                    else
                    {
                        UART2_Write_Text("HDOP:");
                        for(j=0;j<=4;j++)
                                         UART2_Write(HDOP[j]);
                        UART2_Write(' ');
                    }
                    /*Data output alt*/
                    if(zero_alt==1)
                    {
                         UART2_Write_Text("Alt:");
                         UART2_Write_Text("0000.0 ");
                          UART2_Write(13);
                          zero_alt=0;
                    }
                    else
                    {
                        UART2_Write_Text("Alt:");
                        for(j=0;j<=5;j++)
                        UART2_Write(alt[j]);
                        UART2_Write(' ');
                    }
}

void GNRMC_mode()
{
       coma=0;
                    for(i=5;coma<7;i++)
                    {
                         if(buff_1[i]== ',')
                             coma++;
                    }

                    for(sub_count=0;coma<8;i++)
                    {
                          if(buff_1[i]== ',')
                          {
                                         coma++;
                                         if(sub_count==0) zero_spd_k=1;
                          }
                          else
                          {
                             spd_k[sub_count]=buff_1[i];
                             sub_count++;
                          }
                    }

                    i=0;
                    /*Data output spd_k*/
                    if(zero_spd_k==1)
                    {
                         UART2_Write_Text("Spd_Over_Ground:");
                         UART2_Write_Text("000.000 k ");
                         zero_spd_k=0;
                    }
                    else
                    {
                        UART2_Write_Text("Spd_Over_Ground:");
                        for(j=0;j<=6;j++)
                                         UART2_Write(spd_k[j]);
                        UART2_Write_Text("k ");
                    }
}

void GNVTG_mode()
{
     coma=0;
                    for(i=5;coma<7;i++)
                    {
                         if(buff_1[i]== ',')
                             coma++;
                    }




                    for(sub_count=0;coma<8;i++)
                    {
                          if(buff_1[i]== ',')
                          {
                             coma++;
                             if(sub_count==0) zero_spd_kph=1;
                          }
                          else
                          {
                             spd_kph[sub_count]=buff_1[i];
                             sub_count++;
                          }
                    }
                i=0;
                /*Data output spd_kph*/
                    if(zero_spd_kph==1)
                    {
                         UART2_Write_Text("Spd_over_ground:");
                         UART2_Write_Text("00.000Km/h");
                         UART2_Write(13);
                         zero_spd_kph=0;
                    }
                    else
                    {
                        UART2_Write_Text("Spd_over_ground:");
                        for(j=0;j<=6;j++)
                        UART2_Write(cog_t[j]);
                        UART2_Write_Text("Km/h ");
                        UART2_Write(13);
                    }
}


void U1RX() iv IVT_ADDR_U1RXINTERRUPT ics ICS_AUTO {

       dat_buff=UART1_READ();
       switch(dat_buff)
       {
             case '$':
                {
                      flag_start=1;
                      flag_star=0;
                      count=0;
                      break;
                }
             case '*':
                {
                      flag_star=1;
                      break;
                }

       }
       if(flag_start==1)
       {
             buff[count]=dat_buff;
             count++;
             if(count>=99) count=0;
        }
       IFS0.U1RXIF=0;
}



void main()
{
           IFS0.U1RXIF=0;
           IEC0.U1RXIE=1;
           UART1_Init(9600);
           UART2_Init(9600);
           Delay_ms(100);
           while(1)
         {
               strcpy(buff_1, buff);
               if(flag_star==1)
               {
                    if( buff_1[1]== 'G' && buff_1[2]=='N' && buff_1[3]=='G' && buff_1[4]== 'G' && buff_1[5]== 'A' )
                               mode=1; //GNGGA=1
                    if( buff_1[1]== 'G' && buff_1[2]=='N' && buff_1[3]=='R' && buff_1[4]== 'M' && buff_1[5]== 'C' )
                               mode=2; //GNRMC=2
                    if( buff_1[1]== 'G' && buff_1[2]=='N' && buff_1[3]=='V' && buff_1[4]== 'T' && buff_1[5]== 'G' )
                               mode=3; //GNVTG=3
                    if( buff_1[1]== 'G' && buff_1[2]=='N' && buff_1[3]=='G' && buff_1[4]== 'S' && buff_1[5]== 'A' )
                               mode=4; //GNGSA=4

                    switch(mode)
                    {
                          case 1: GNGGA_mode();
                          case 2: GNRMC_mode();
                          case 3: GNVTG_mode();
                    }
               }


          }


}
