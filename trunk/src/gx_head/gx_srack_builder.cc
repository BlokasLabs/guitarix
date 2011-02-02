/*
* Copyright (C) 2009, 2010 Hermann Meyer, James Warden, Andreas Degert
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
* ---------------------------------------------------------------------------
*
*    This file is a part ofthe gx_head interface builder
*    and build the stereo effect rack,
*    it's a part of the class GxMainInterface
*
* ----------------------------------------------------------------------------
*/


openHorizontalTableBox("");
{
	// add controllers without show them
     openHorizontalhideBox("");
     {
		 create_small_rackknob("jconv.balance");
		 create_small_rackknob("jconv.diff_delay");
		 create_small_rackknob("jconv.gain");
		 create_small_rackknob("jconv.wet_dry");
		 create_hslider("amp.balance", "balance");

     }
     closeBox();

     //----- chorus
     openHorizontalRestetBox(_("chorus"), &gx_engine::audio.posit8);
     {
          openVerticalBox(_("chorus"));
          {

               openHorizontalTableBox("");
               {
                    openPaintBox1("");
                    {
                         create_switch_no_caption(sw_switchit, "chorus.on_off");
                    }
                    closeBox();

                    opensDialogBox("chorus.dialog", "chorus.on_off","RackBox_expose");
                    {

                         openVerticalBox("");
                         {
                              openHorizontalBox("");
                              {
                                   create_small_rackknobr("chorus.level",_("  level  "));
                                   create_small_rackknob("chorus.delay",_("  delay  "));
                                   create_small_rackknob("chorus.depth",_("  depth  "));
                                   create_small_rackknob("chorus.freq",_("  freq  "));
                              }
                              closeBox();
                         }
                         closeBox();
                    }
                    closeBox();

               }
               closeBox();
          }
          closeBox();
     }
     closeBox();
     //end chorus

     openHorizontalRestetBox(_("flanger"), &gx_engine::audio.posit9);
     {
          openVerticalBox(_("flanger"));
          {

               openHorizontalTableBox("");
               {
                    openPaintBox1("");
                    {
                         create_switch_no_caption(sw_switchit, "flanger.on_off");
                    }
                    closeBox();
                    opensDialogBox("flanger.dialog", "flanger.on_off","RackBox_expose");
                    {

                         openHorizontalBox("");
                         {
                              openHorizontalBox("");
                              {
                                   create_small_rackknobr("flanger.level",_("  level  "));
                              }
                              closeBox();
                              openVerticalBox("");
                              {
                                   openHorizontalBox("");
                                   {
                                        create_small_rackknob("flanger.feedback gain",_(" feedback "));
                                        create_small_rackknob("flanger.depth",_("  depth  "));
                                        create_small_rackknob("flanger.flange delay",_("  delay  "));
                                        create_small_rackknob("flanger.flange delay offset",_(" delay offset"));
                                        create_small_rackknob("flanger.LFO freq",_(" LFO "));

                                   }
                                   closeBox();
                                   openSpaceBox("");
                                   closeBox();
                                   openHorizontalBox("");
                                   {
                                        openSpaceBox("");
                                        closeBox();
                                        create_selector("flanger.invert");
                                        openSpaceBox("");
                                        closeBox();
                                        openSpaceBox("");
                                        closeBox();
                                        openSpaceBox("");
                                        closeBox();
                                        openSpaceBox("");
                                        closeBox();
                                        openSpaceBox("");
                                        closeBox();
                                        openSpaceBox("");
                                        closeBox();
                                   }
                                   closeBox();
                                   openFrameBox("");
                                   closeBox();
                              }
                              closeBox();

                         }
                         closeBox();
                    }
                    closeBox();

               }
               closeBox();
          }
          closeBox();
     }
     closeBox();



     openHorizontalRestetBox(_("phaser"), &gx_engine::audio.posit12);
     {
          openVerticalBox(_("phaser"));
          {

               openHorizontalTableBox("");
               {
                    openPaintBox1("");
                    {
                         create_switch_no_caption(sw_switchit, "phaser.on_off");
                    }
                    closeBox();
                    opensDialogBox("phaser.dialog", "phaser.on_off","RackBox_expose");
                    {
                         openHorizontalBox("");
                         {
                              openHorizontalBox("");
                              {
                                   create_small_rackknobr("phaser.level",_("  level "));
                              }
                              closeBox();
                              openVerticalBox("");
                              {
                                   openHorizontalBox("");
                                   {
                                        create_small_rackknob("phaser.feedback gain",_(" feedback "));
                                        create_small_rackknob("phaser.depth", _("depth"));
                                        create_small_rackknob("phaser.Notch width", _("width"));
                                        create_small_rackknob("phaser.NotchFreq", _("freq"));
                                        create_small_rackknob("phaser.MaxNotch1Freq", _("max Hz"));
                                        create_small_rackknob("phaser.MinNotch1Freq", _("min Hz"));
                                        create_small_rackknob("phaser.Speed", _("speed"));
                                   }
                                   closeBox();
                                   openSpaceBox("");
                                   closeBox();
                                   openHorizontalBox("");
                                   {
                                        openSpaceBox("");
                                        closeBox();
                                        create_selector("phaser.invert");
                                        openSpaceBox("");
                                        closeBox();
                                        create_selector("phaser.VibratoMode");
                                        openSpaceBox("");
                                        closeBox();
                                        openSpaceBox("");
                                        closeBox();
                                        openSpaceBox("");
                                        closeBox();
                                        openSpaceBox("");
                                        closeBox();
                                        openSpaceBox("");
                                        closeBox();
                                   }
                                   closeBox();
                                   openFrameBox("");
                                   closeBox();
                              }
                              closeBox();
                         }
                         closeBox();
                    }
                    closeBox();
               }
               closeBox();
          }
          closeBox();
     }
     closeBox();

     openHorizontalRestetBox(_("delay"), &gx_engine::audio.posit15);
     {
          openVerticalBox(_("delay"));
          {

               openHorizontalTableBox("");
               {
                    openPaintBox1("");
                    {
                         create_switch_no_caption(sw_switchit, "stereodelay.on_off");
                    }
                    closeBox();
                    opensDialogBox("stereodelay.dialog", "stereodelay.on_off","RackBox_expose");
                    {

                         openVerticalBox("");
                         {
                              openHorizontalBox("");
                              {
                                   create_small_rackknob("stereodelay.l_gain",_("left gain"));
                                   create_small_rackknob("stereodelay.l_delay",_("left delay"));
                                   openVerticalBox("");
                                   {
                                        create_small_rackknobr("stereodelay.LFO freq",_("LFO"));
                                        openSpaceBox("");
                                        closeBox();
                                        create_selector("stereodelay.invert");
                                        openFrameBox("");
                                        closeBox();
                                   }
                                   closeBox();

                                   create_small_rackknob("stereodelay.r_gain",_("right gain"));
                                   create_small_rackknob("stereodelay.r_delay",_("right delay"));

                              }
                              closeBox();
                         }
                         closeBox();
                    }
                    closeBox();
               }
               closeBox();
          }
          closeBox();
     }
     closeBox();

     openHorizontalRestetBox(_("echo"), &gx_engine::audio.posit16);
     {
          openVerticalBox(_("echo"));
          {

               openHorizontalTableBox("");
               {
                    openPaintBox1("");
                    {
                         create_switch_no_caption(sw_switchit, "stereoecho.on_off");
                    }
                    closeBox();
                    opensDialogBox("stereoecho.dialog", "stereoecho.on_off","RackBox_expose");
                    {

                         openVerticalBox("");
                         {
                              openHorizontalBox("");
                              {
                                   create_small_rackknob("stereoecho.percent_l",_("left %"));
                                   create_small_rackknob("stereoecho.time_l",_("left time"));
                                   create_small_rackknob("stereoecho.percent_r",_("right %"));
                                   create_small_rackknob("stereoecho.time_r",_("right time"));

                              }
                              closeBox();
                         }
                         closeBox();
                    }
                    closeBox();
               }
               closeBox();
          }
          closeBox();
     }
     closeBox();

     openHorizontalRestetBox(_("moog"), &gx_engine::audio.posit11);
     {
          openVerticalBox(_("moog"));
          {

               openHorizontalTableBox("");
               {
                    openPaintBox1("");
                    {
                         create_switch_no_caption(sw_switchit, "moog.on_off");
                    }
                    closeBox();
                    opensDialogBox("moog.dialog", "moog.on_off","RackBox_expose");
                    {

                         openVerticalBox("");
                         {
                              openHorizontalTableBox("");
                              {
                                   create_small_rackknob("moog.Q",_("            Q            "));

                                   create_small_rackknob("moog.fr",_("            Hz           "));

                              }
                              closeBox();
                         }
                         closeBox();
                    }
                    closeBox();
               }
               closeBox();
          }
          closeBox();
     }
     closeBox();
     
     openHorizontalRestetBox(_("amp"), &gx_engine::audio.posit19);
     {
          openVerticalBox(_("reamp"));
          {

               openHorizontalTableBox("");
               {
                    openPaintBox1("");
                    {
                         create_switch_no_caption(sw_switchit, "ampmodul.on_off");
                    }
                    closeBox();
                    opensDialogBox("ampmodul.dialog", "ampmodul.on_off","RackBox_expose");
                    {

                         openVerticalBox("");
                         {
                              openHorizontalBox("");
                              {
								   openSpaceBox("");
                                   closeBox();
                                   create_small_rackknobr("ampmodul.feedbac",_("dry/feedback  "));
                                   create_small_rackknob("ampmodul.wet_dry",_("dry/wet"));
								   create_small_rackknob("ampmodul.level",_("level"));
                                   create_small_rackknob("ampmodul.amp2.stage1.tube1",_("tube1"));
                                   create_small_rackknob("ampmodul.amp2.stage2.tube2",_("tube2"));
                                   create_small_rackknobr("ampmodul.feedback",_("  wet/feedback"));
                                   openSpaceBox("");
                                   closeBox();

                              }
                              closeBox();
                         }
                         closeBox();
                    }
                    closeBox();
               }
               closeBox();
          }
          closeBox();
     }
     closeBox();
     
     
     
     openHorizontalhideBox1("");
     {
create_hslider("amp.balance", "balance");
     }
     closeBox();

}
closeBox();
