/*
 * tctutorial.h
 *
 * by Stein Kulseth <steink@opera.com>, 2003
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * $Id$
 */
/* Time control tutorial */

char *aszTcTutorial [] = {
"Time Controls in GNUBG - Short Tutorial",
"---------------------------------------",
"",
"1. Using the time controls",
"",
"Once you have defined named time controls using them is quite easy.",
"You just issue the command:",
"  set tc <name>",
"where <name> is the name of the wanted time control setting, and you",
"are ready to rock.",
"Or if using the graphical user interface you find the defined",
"Time Controls under 'Settings/Time Controls'",  
"",
"With the graphical user interface you should see the clock ticking ",
"once you start play - with the terminal interface the clock will be",
"updated in each new board, and you can include '\\t' in your prompt",
"to have the clock show in your prompt.",
"",
"You can use:",
"  show tclist",
"to see the list of currently defined time control settings, and:",
"  show tc",
"to see the details of the current time control setting.",
"",
"And to turn the thing off you use:",
"  set tc off",
"",
"2. Clock types ",
"",
"Gnubg supports four clock types:",
"  Plain",
"    Each player's clock counts down from a set amount to zero.",
"  Bronstein",
"    Each player gets a few seconds free time for each move.",
"    Only after this is used up does the clock start.",
"  Fischer",
"    Each player gets a few seconds added to his clock at the start",
"    of each move. If he uses less than that he actually gains time.",
"  Hourglass",
"    The time subtracted from one player's clock gets added to the other.",
"",
"When the clock reaches zero, penalties apply - this can be either",
"  Point penalty",
"    The other player is awarded a number of points.",
"  Match loss penalty",
"    The other players wins.",
"",
"Also - unless the match is over - the clock settings for one or both",
"of the players will be updated.",
"This typically includes adding more time, and possibly also changing",
"the clock type, the penalty,  or other parameters.",
"",
"3. Defining time controls",
"",
"The easy way is to just open the example file 'tcexamples.txt' with the",
"File/Open/Commands command, and then you will immediately have a few", 
"sensible time control settings to play with.",
"",
"But you can also create or modify time control settings yourself with",
"the commands:",
"",
"  set tctype plain | bronstein | fischer | hourglass | none",
"    Clock type as explained above",
"  set tcpenalty <n> | lose",
"    An integer means point penalty on clock expiry,",
"    'lose' means match lloss penalty.",
"  set tctime <time>",
"    Time that is added to the player's clock at the start of",
"    the current time control. This can be either at the start of",
"    the match, or when the time control is updated after clock expiry.",
"  set tcpointtime <time>",
"    Time that is added to the player's clock at the start of the",
"    the current time control, like the above, but this time is multiplied",
"    by the sum of remaining points in the match.",
"    E.g. at the start of a 5 point match, <time> will be multiplied",
"    by 10.",
"  set tcmovetime <time>",
"    The time per move applying to Bronstein or Fischer time controls.",
"  set tcmultiplier <factor>",
"    When updating the time control after expiry, you can choose to",
"    scale the remaining time on the clock by a real factor.",
"    If you set this to 0.0 then any remaining time is discarded and",
"    the player will start from scratch with only what is allocated by ",
"    the new time control.",
"    Default value is 1.0 - keeping all of time remaining on the clock.",
"  set tcnext <next>  [ <opp next> ]",
"    This is the new time control to install after clock expiry, for",
"    the player who has run out, and optionally also for the opponent",
"    player. ",
"  set tcname <name>",
"    Name these time control settings, or apply to an existing named",
"    time control.",
"",
"These commands always modify your current time control settings,",
"which most often is a working copy of some named time control settings.",
"They do not affect the named version, unless you select to apply",
"them with the 'set tcname' command.",
"",
"Naming time controls allow for easy reference, for storage in your",
".gnuautorc file as well, and it is needed in order to implement",
"clock strategies that have primary and secondary (and possibly tertiary and",
"quarternary ...) time controls. It is also needed to implement time",
"controls that penalize different amounts of points, and add different",
"amounts of time.",
"",
"Example, in order to implement standard backgammon tournament clock rules",
"(e.g Chicago Bar Point, or Nordic Wide Open rules), you will need 3 defined",
"time controls:",
"  a The first that adds the initial amount, and has penalty 2 points.",
"  b The second for the first player to run out, that adds 5 minutes and has",
"    penalty 1 point.",
"  c The second for the opponent, that adds 5 minutes but still has penalty",
"    2 points",
"",
"Secondary timecontrols can be given names starting with '.', then they",
"won't show up in the tclist unless you specify 'set tclist all'",
""
"4. Example commands (tcexamples.txt)",
"",
"# Chicago Bar Point rules",
"set tcpenalty 1",
"set tctype plain ",
"set tctime 300",
"set tcpointtime 0",
"set tcmultiplier 1.000000",
"set tcmovetime 0",
"set tcnext .c1",
"set tcname .c1",
"",
"set tcpenalty 2",
"set tcnext .c1",
"set tcname .c2",
"",
"set tcpointtime 180",
"set tcnext .c1 .c2",
"set tcname Chicago",
"",
"#Nordic Wide Open Rules",
"set tcpenalty 2",
"set tctype plain ",
"set tctime 600",
"set tcpointtime 150",
"set tcmultiplier 1.000000",
"set tcmovetime 0",
"set tcnext .c1 .c2",
"set tcname Nordic",
"",
"#Michigan rules",
"set tcpenalty lose",
"set tctype bronstein",
"set tctime 180",
"set tcpointtime 0",
"set tcmultiplier 1.000000",
"set tcmovetime 12",
"set tcnext ",
"set tcname .m2",
"",
"set tcpenalty 0",
"set tctype plain ",
"set tctime 600",
"set tcpointtime 150",
"set tcmovetime 0",
"set tcmultiplier 1.000000",
"set tcnext .m2 .m2",
"set tcname Michigan",
"",
"# Gammonitis club Bronstein timing",
"set tctype bronstein",
"set tcpenalty lose",
"set tctime 0",
"set tcpointtime 1:00",
"set tcmultiplier 1.000000",
"set tcmovetime 12",
"set tcnext ",
"set tcname Gammonitis",
"",
"# Example hourglass timing",
"set tcpenalty 1",
"set tctype hourglass",
"set tctime 2:00 ",
"set tcpointtime 0",
"set tcmultiplier 0.000000",
"set tcmovetime 0",
"set tcnext Hourglass Hourglass",
"set tcname Hourglass",
"",
0 };