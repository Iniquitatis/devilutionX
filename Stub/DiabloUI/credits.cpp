#include "../../types.h"

#define CREDIT_LINES 13

int creditLine;
int ybase;
int lastYbase;
int lineCount;
bool creditEnd;

char *the_long_credits[] = {
	"Game Design",
	"	Blizzard North",
	"",
	"Senior Designers",
	"	Erich Schaefer, David Brevik",
	"",
	"Additional Design",
	"	Max Schaefer, Eric Sexton, Kenneth Williams",
	"",
	"Lead Programmer",
	"	David Brevik",
	"",
	"Senior Programmers",
	"	Richard Seis, Doron Gartner,",
	"	Patrick Wyatt, Mike O'Brien",
	"",
	"Programming",
	"	Peter Brevik, Robin van der Wel, Jon Morin",
	"",
	"Special Guest Programmers",
	"	Collin Murray, Frank Pearce",
	"",
	"Battle.net Programming",
	"	Mike O'Brien, Mike Morhaime, Dan Liebgold",
	"",
	"Serial Communications Programming",
	"	Jeff Strain, Mike O'Brien",
	"",
	"Installer Programming",
	"	Bob Fitch, Patrick Wyatt",
	"",
	"Art Directors",
	"	Erich Schaefer, Samwise Didier",
	"",
	"Artwork",
	"	Michio Okamura, Eric Sexton, Ben Haas, Patrick Tougas,",
	"	Kelly Johnson, Erich Schaefer, Max Schaefer, Hugh Tom",
	"	Byrne, Roman Kenney, Samwise Didier, Dave Berggren,",
	"	Micky Neilson, Eric Flannum, Justin Thavirat, Brian",
	"	Sousa, Stu Rose, Nick Carpenter, Joeyray Hall",
	"",
	"Technical Artwork",
	"	Christopher Root, Mark Sutherland,",
	"	Robert Djordjevich, Jeffrey Vaughn",
	"",
	"Cinematic Art Directors",
	"	Duane Stinnett, Matt Samia",
	"",
	"3D Cinematic Artwork",
	"	Duane Stinnett, Matt Samia, Rob McNaughton,",
	"	Eric Flannum, Dave Pursley, Micky Neilson,",
	"	Maxx Marshall, Trevor Jacobs, Brian Sousa,",
	"	Samwise Didier, Ron Smorynski, Ben Haas, Patrick Tougas",
	"",
	"Cinematic Technical Artwork",
	"	Joeyray Hall ",
	"",
	"Executive Producer",
	"	Allen Adham",
	"",
	"Producer",
	"	Bill Roper",
	"",
	"Associate Producer",
	"	James Phinney",
	"",
	"Diablo Strike Team",
	"	Allen Adham, Ron Millar, Mike O'Brien,",
	"	James Phinney, Bill Roper, Patrick Wyatt",
	"",
	"Music",
	"	Matt Uelmen",
	"",
	"Sound Design",
	"	Matt Uelmen, Glenn Stafford",
	"",
	"Cinematic Music & Sound",
	"	Glenn Stafford, Matt Uelmen",
	"",
	"Voice Production, Direction & Casting",
	"	Mark Schwarz, Glenn Stafford, Bill Roper",
	"",
	"Script & Story",
	"	Erich Schaefer, Eric Sexton,",
	"	Chris Metzen, Bill Roper",
	"",
	"Voice Editing",
	"	Glenn Stafford",
	"",
	"Voices",
	"	Michael Haley, Glynnis Talken, Michael Gough,",
	"	Paul Eiding, Lani Minella, Steve Brodie, Bill Roper,",
	"	Mark Schwarz, Glenn Stafford, Chris Metzen, Max Schaefer",
	"",
	"Recording Engineer",
	"	Robert Koenigsberg",
	"",
	"Manual Design & Layout",
	"	Peter Underwood, Jeffrey Vaughn,",
	"	Chris Metzen, Bill Roper",
	"",
	"Manual Artwork",
	"	Samwise Didier, Chris Metzen,",
	"	Roman Kenney, Maxx Marshall",
	"",
	"Provisional Director of QA (Lead Tester)",
	"	Shane Dabiri",
	"",
	"QA Assault Team (Testers)",
	"	Christopher Cross, Mike Givens, Dave Hale,",
	"	Brian \"Doc\" Love, Hung Nguyen, Dean Shipley,",
	"	Chris Sigaty, Ian Welke, Jamie Wiggs",
	"",
	"QA Special Ops Team (Compatibility Testers)",
	"	Adam Maxwell, Russell \"Rug\" Miller",
	"",
	"QA Artillery Support (Additional Testers) ",
	"	Rich Alcazar, Mike Jones, Rev. Dan Moore, Matt Morris,",
	"	Mark Pfeiffer, Harish \"Pepe the Enforcer\" Rao, Chris Millar",
	"",
	"QA Counterintelligence",
	"	Alan Dabiri, Jesse McReynolds, Walter Takata",
	"",
	"Order of Network Information Services",
	"	Robert Bridenbecker, Jason \"Brother Shaggy\" Schmit,",
	"	Jamie \"Brother Gug\" Steigerwald, Richard Seis ",
	"",
	"Customer Support",
	"	John Schwartz, Vic Larson, Chad Chaudry, Mick Yanko,",
	"	Brandon Riseling, Kirk Mahony, Tony Hardy, Richard",
	"	Amtower, Collin Smith, Andrew Edwards, Roger Eberhart",
	"",
	"Sales",
	"	Jorge Rivero, Rob Beatie",
	"",
	"Dunsel",
	"	Alan Dabiri",
	"",
	"Mr. Dabiri's Background Vocalists",
	"	Karin Colenzo, Christina Cade,",
	"	Kim Farrington, Melissa Edwards",
	"",
	"Public Relations",
	"	Linda Duttenhaver, Susan Wooley",
	"",
	"Marketing",
	"	John Patrick, Steve Huot, Neal Hubbard, Kathy Carter",
	"",
	"International Sales",
	"	Ralph Becker, Chris Yoshimura",
	"",
	"U.S. Sales",
	"	Todd Coyle, Danny Kearns",
	"",
	"Manufacturing",
	"	John Goodman, Tom Bryan",
	"",
	"Legal & Business",
	"	Paula Duffy, Eric Roeder, Paul Sams, Kenneth Williams",
	"",
	"Special Thanks To",
	"	Primenet, Earthlink, AOL, Compuserve, ATI, Matrox, STB, ",
	"	Creative Labs, Logitech, U.S. Robotics, Gravis, Cyrix",
	"",
	"Thanks To",
	"	Ian Colquhoun, Rod Shean, Brian Fitzgerald, Sharon Schafer, Todd ",
	"	Schafer, Richard and Sandra Schaefer, Rick Bowles, Greg Bogden, ",
	"	Cindy Sievert, Brad Mason, Chuck Goldman, Karin Colenzo, Wendy ",
	"	Brevik, Jennie Brevik, Hanna Carroll, Katie Newell, Karen Weiss, ",
	"	Kurt Beaver, Stan McDonald, Brian Sexton, Michael Wan, Megan ",
	"	Williams, Jessica Gensley, Beth Ann Parks, Brian Piltin, Johnathan ",
	"	Root, Brett Supernaw, Sabeer Bhatia, Mark Rearick, Brad Mason, ",
	"	Diane Kodama, Bernadette Sexton, Barbara Uhlmann, Patricia",
	"	McDonald, Kris Kelley, Alissa Vaage, Denise Hernandez, Paula ",
	"	White, Rachel Marie Hawley, Laura Gaber, Isaac Matarasso,",
	"	Susan Stafford, Gretchen Witte, Jason Sailor, Eufemia Palomino, ",
	"	Nathalie Didier, Nicole Welke, Dawn Caddel, Anna-Marcelle ",
	"	Okamura, Amber Okamura, Megan Okamura Tracey McNaughton, ",
	"	Trisha Ann Ochoa, Annie Strain, Dr. Gregory T. Street, Ray the Soda ",
	"	Guy, Sam Raimi, A. Guinness Brewing Co., John Woo, Chow Yun Fat, ",
	"	Jackie Chan,Proposition 215, Rumiko Takahashi, Bunchy & Mason, ",
	"	The Friends of Stan, The Zoo Crew, Team Hamro, Brazil 2001, RUSH, ",
	"	Cornholio, THE BROS., Dar, Emeril Lagasse, Tom Waits, Ice-Cube, ",
	"	The Strike Team Deflectors, Tony Levin, Big Jim and the Twins, ",
	"	Jag`rmeister, The Megasphere, Condor, The Allower, The Sunday ",
	"	Night Group, Gravitar, Steinway Pianos, Round Table Pizza, The Poxy ",
	"	Boggards, Urban Mystic & Co., Caffeine, Hunter Rose, Marly ",
	"	mediums in the box, sweet Poteen, Dave Scarpitti, TheByter, Bim ",
	"	Man, Krissann for color, Patty at Avalon Tattoo, James, Whaleboy, ",
	"	Dunsel Training Institute, monkeys, Dob Bole, Rootes Group, Porshe, ",
	"	Bongo, Scarlett, Apollo, The House of Mediocrity, Amelias, The King, ",
	"	Saag and all the folks at Davidson",
	"",
	"In memory of",
	"	Lawrence and Barbara Williams",
	"	David A. Hargrave",
	"	Tony \"Xatre\" Collin",
	"	Thomas H Sexton",
	"",
	"Very Special Thanks to",
	"	Bob and Jan Davidson",
	"	Walter Forbes",
	"",
	"The Ring of One Thousand",
	"	Andrew Abernathy, Christopher Abramo, David Adams, David ",
	"	Adcox, Marko Agterberg, Cory Aiken, Judah Altaras, John ",
	"	Alvarez, Jose Alvarez, Richard Amable, Alexander Amaral, ",
	"	Scott Amis, Vincent Amoroso, Mark An, David Andersen, Jason ",
	"	Andrew Abernathy, Christopher Abramo, David Adams, David ",
	"	Adcox, Marko Agterberg, Cory Aiken, Judah Altaras, John ",
	"	Alvarez, Jose Alvarez, Richard Amable, Alexander Amaral, ",
	"	Scott Amis, Vincent Amoroso, Mark An, David Andersen, Jason ",
	"	Andersen, Aaron Anderson, George Anderson, Matthew ",
	"	Anderson, Michael Anderson, Sean Anderson, Robert Andrade, ",
	"	Cerny Andre, Michael Andreev, Devin Angle, Brian Apple, ",
	"	Brian Arbuthnot, Billy Arden, Dorian Arnold, Andre Arsenault, ",
	"	Erik Asplund, Mark Assam, John Athey, Jason Attard, Jeff ",
	"	Atwood, Ricky Au, Scott Avery, Rand Babcock, Steve Babel, ",
	"	Raymond Bacalso, Ed Bachta, Steven Back, Scott Baeder, Alex ",
	"	Baevski, Scott Bailey, Kenneth Baird, Thomas Baker, Todd ",
	"	Bala, Jan Ball, Greg Baltz, Blake Baltzley, Doug Bambrick, Wes ",
	"	Bangerter, Paul Barfuss, Chris Barghout, Dave Barnebey, Jon ",
	"	Barnhart, Terje Barth, Nicole Baskin, Bernard Baylen, Ryan ",
	"	Bear, Phil Bedard, Todd Belcher, Chip Bell, Erez Ben-Aharon, ",
	"	Jonathan Bender, Nick Bennett, Ireney Berezniak, Ted Berg, ",
	"	Gunnar Bergem, Russell Beuker, Ed Bickford, Stephen Biles, ",
	"	John Billdt, Gerald Binder, John Bird, Hannah Blackerby, Tom ",
	"	Blackerby, Clayton Blackwell, Thomas Blake, Shawn Blaszak, ",
	"	Daniel Bliss, Fred Bliss, Jeff Bliss, Jon Blum, Rune Boersjoe, ",
	"	Andrew Boggs, Dave Boisvenu, Joe Bolt, John Bonds, Jeff ",
	"	Borenstein, Dorian Borin, Ed Boris, Bartholomew Botta, ",
	"	Michael Boutin, Michael Boyd, Charles Boyer, Mike ",
	"	Boyersmith, Michael Boyko, Eric Bradberry, John Brandstetter, ",
	"	Ryan Breding, Paul Brinkmann, Patrick Briscoe, Scott Brisko, ",
	"	Jeremy Britton, Adrian Broadhead, Glenn Brouwer, Joe Brown, ",
	"	Sébastien Brulotte, Darrell Brunsch, William Bryan, Jason ",
	"	Bucher, Chris Buchinger, Clayton Buckingham, John Buckles, ",
	"	David Bugay, Ed Bujone, Erik Burgess, Gabriel Burkett, Chris ",
	"	Burnes, Richard Butler, Jeffrey Bye, Dougall Campbell, Donnie ",
	"	Cannon, Shane Cantrell, Connor Caple, Daniel Carey, James ",
	"	Carlton, Michael Carmel, Mike Carpenter, Ronald Carruthers, ",
	"	Phil Carter, Bryce Cartmill, Eric Cartwright, Anthony Caruso, ",
	"	Lon Casey, Tim Caster, Aaron Chan, Otto Chan, Gene Chang, ",
	"	Hsiao-Lung Chang, William Chang, George Chappel, Larry ",
	"	Charbonneau, Troy Chase, Bruce Chen, Chun Hsien Chen, Sam ",
	"	Chen, Tzu-Mainn Chen, Mike Cheng, Chris Chiapusio, Damien ",
	"	Chiesa, Nick Chin, Nim Ching, Jonathan Chinn, Michael Chinn, ",
	"	Philander Chiu, Thayne Christiansen, Philip Chui, Steve ",
	"	Cintamani, Richard Ciordia, Colin Clark, Steve Clark, Samuel ",
	"	Clements, Meredith Clifton, Jeff Cohen, Dale Colton, Dax ",
	"	Combe, Matt Compton, Jacob Conklin, Richard Conn, Zac ",
	"	Cook, Tim Coolong, Gregory Coomer, Dennis Cosgrove, Kelly ",
	"	Couch, Andrew Coulter, Eric Coutinho, David Coutts, James ",
	"	Craig, John Craig, Kazial Craig, John Crawford, Marcelo ",
	"	Crespo, Orville Crews, Tim Cristy, Elmer Crosby III, Russell ",
	"	Cullison, Ryan Cupples, Andrew Dagley, Steve Dallaire, Richard ",
	"	Dalton, David Dandar, Pro Daulo, Rob Dautermann, Mike ",
	"	Davies, Kalieb Davis, Marshall Davis, Ronald Davis, Danny De ",
	"	Bie, Marc De Filippis, Myles Deighton, Kent Dejarnett, Anthony ",
	"	Delarosa, Neil Dempster, Peter Denitto, Joaquim Dentz, Scott ",
	"	Dewar, Anish Dhingra, Philip Dhingra, David Diaz, Stewart ",
	"	Dicks, Brad Dietz, Josh Dietz, Colleen Diggins, Mike Ditchburn, ",
	"	Eric Dittman, Allen Do, Huy Doan, Matthew Dolman, Antoine ",
	"	Dongois, Eamonn Donohoe, Bill Dorell, Mark Dorison, Dan ",
	"	Dorsett, Chris Dorsey, Jim Dosé, Willis Doss, Chin Du, William ",
	"	Dubis, Timothy Duewell, Brandon Dunn, Andrew Durham, Don ",
	"	Duvall, Kevin Dvojack, Daniel Eaton, Paul Eberting, Eric ",
	"	Echelbarger, Lance Eddleman, Ben Eggers, David Eggum, John ",
	"	Ehde, Brian Eikenberry, Patrick Elven, Peter Engdahl, Philip ",
	"	Engdahl, Michael Ennis, Darren Eslinger, Eric Ezell, Darren ",
	"	Falslev, Stephen Feather, Tony Fenn, Ben Ferguson, Mike ",
	"	Fernandez, Gwendal Feuillet, Guy Fietz, Julian Figueroa, Dale ",
	"	Fillpot, Stan Finchem, Michael Finley, Nick Fisher, William ",
	"	Fisher, Mark Fitlin, Dave Flatt, Joel J. Flores, John Folkers, ",
	"	Steven Forgie, Tom Forsythe, Matthew Foster, Scott Francis, ",
	"	Jim Frank, Paulo Fraser, Glenn French, Kurt Frerichs, Chris ",
	"	Frey, Mark Friedman, Charles Friedmann, Dan Friend, Kirk ",
	"	Fry, Aaron Fu, Erik Gaalema, Brandon Gabbard, Phil Gagner, ",
	"	Tommy Gannon, David Gappmayer, Chris Garrison, Tony ",
	"	Garrison, David Gasca, Jeremy Gasser, Michael Geist, Michael ",
	"	Genereux, Daniel Genovese, Josh Gerwin, Paul Gibson, William ",
	"	Gilchrist, Gabriel Gils Carbo, Chad Glendenin, Ryan Glinski, ",
	"	Dean Gobrecht, Andrew Goldfinch, David Goodman, Mark ",
	"	Goodson, Matt Gordon, Frank Gorgenyi, Sean Gould, Perry ",
	"	Goutsos, Ed Govednik, Michael Grayson, Chris Green, Justin ",
	"	Grenier, Jeff Greulich, Don Grey, Rob Griesbeck, Don Griffes, ",
	"	Kimberly Griffeth, Jay Grizzard, Don Gronlund, Joe Gross, ",
	"	Troy Growden, Greg Guilford, David Gusovsky, Jeremy ",
	"	Guthrie, Adam Gutierrez, James Guzicki, Matthew Haas, Matt ",
	"	Hadley, Ryan Hagelstrom, Bobby Hagen, Ben Hall, Brian Hall, ",
	"	Kris Hall, Calvin Hamilton, Kris Hamilton, Bo Hammil, Dave ",
	"	Hans, Rick Hansen, Robert Harlan, Travis Harlan, Seth ",
	"	Harman, Jeff Harris, Shawn Hartford, Adam Hartsell, Neil ",
	"	Harvey, Ray Hayes, John Hein, Chris Heinonen, Christer ",
	"	Helsing, Chris Hempel, Dustin Hempel, Mathieu Henaire, Matt ",
	"	Henry, Chuck Herb, Michael Herron, Sage Herron, Thomas ",
	"	Herschbach, Cliff Hicks, Nelson Hicks, Paul Hierling, William ",
	"	Hiers, Mike Higdon, Tim Hildebrand, Casey Hinkle, Ryan ",
	"	Hitchings, Wes Hix, Alan Ho, Jenson Ho, Alan Hoffman, Jeff ",
	"	Hoffman, Eleanor Hoffmann, Steve Hogg, Richard Holler, Brian ",
	"	Homolya, Wade Hone, Joe Horvath, Jeff Howe, Eric Hudson, ",
	"	Glen Huey, Chris Hufnagel, Joshua Hughes, Melissa Hughes, ",
	"	Arief Hujaya, Thomas Hulen, Ryan Hupp, Justin Hurst, Rick ",
	"	Hutchins, Steve Iams, Mike Iarossi, Bjorn Idren, Johan Idrén, ",
	"	Micah Imparato, Joe Ingersoll, David Ingram, Greg Ipp, Rodney ",
	"	Irvin, Darin Isola, Justin Itoh, Mario Ivan, Fredrik Ivarsson, ",
	"	Dax Jacobson, Michael Jacques, Stevens Jacques, Duane Jahnke, ",
	"	William Jambrosek, Daniel Janick, Narciso Jaramillo, Neil ",
	"	Jariwala, Harvie Jarriell, Scott Javadi, Joe Jenkins, Bart ",
	"	Jennings, Paul Jennings, Julien Jenny, Jason Jensen, Martin ",
	"	Jeremy, Mark Jeschke, Andy Johnson, James Johnson, Leigh ",
	"	Johnson, Mark Johnson, Rupert Johnson, Clyde Jones, Michael ",
	"	Jones, Tim Jordan, Ben Judy, Michael Kaae, Steve Kaczkowski, ",
	"	Neville Kadwa, Brian Kaisner, Yoshihisa Kameyama, Michael ",
	"	Kanemura, Daniel Kao, Eric Karabin, Ben Katz, Christopher ",
	"	Kawamura, Erick Kayser, Craig Keddie, Kevin Kelley, Bryan ",
	"	Kemp, Michael Kendrigan, Dan Kerber, Timothy Kerber, Tomi ",
	"	Keski-Heikkilä, Greg Kettering, Nathan Kilber, Howard Kim, ",
	"	Orrin Kinion, Jon Kirst, David Kitch, John Klingbeil, Neil ",
	"	Klopfenstein, Kerry Knouse, David Knox, Said Kobeissi, Jeff ",
	"	Koches, Hades Kong, Jeff Kong, Kevin Konkle, Steve Koon, ",
	"	David Koontz, Dan Koopmann, Steve Koskela, Kuan Kou, ",
	"	Cameron Kracke, Jensen Krage, York Kramer, Cedar Kraus, ",
	"	Jason Kraus, Bobby Krimen, Melissa Krispli, Steven Krispli, ",
	"	James Kruger, Charles Kubasta, Kimmo Kulonen, Frank ",
	"	Lackaff, Michael Lacour, Matt Lake, Jason Landry, Hans Erik ",
	"	Lange, Michael Laramee, Brad Lascelle, Pat Laschinger, Alan ",
	"	Lau, Sean Laurence, Anthony Lavey, Jr., Gary Le, Huey Le, ",
	"	Stephane Le Roy Audy, Lim Leandro, Charles Lee, Conroy Lee, ",
	"	Mike Lee, Shih-Hang Lee, Jonathan Leipert, Jason Lemann, ",
	"	Ron Lenzi, Mitchell Leon, Stephanie Lesniewski, Brendan ",
	"	Lewis, Robert Lewis, Sam Liao, Tom Liem, Adam Ligas, Steven ",
	"	Liggett, Roger Lilley, Benjamin Lim, Jeff Lindholm, Johnson ",
	"	Linwood, David Litchman, Bruce Lithimane, William Liu, ",
	"	Wilson Liu, Robert Lobdell, Chris Logan, Razvan Loghin, Jack ",
	"	Loh, George Loo, Russell Love, Juan Loyola, Ricardo Lozano, ",
	"	Mike Luban, Tim Luc, Henry Luciano, Dianne Ludwig, Charles ",
	"	Lueras, Derek Lung, Phong Ly, Scott MacGillivray, Dave Mack, ",
	"	Alec Mak, Steve Mamayek, Michael Mancini, Daniel Mann, ",
	"	Michael Mann, Chris Manofsky, Abdullah Marafie, Nicholas ",
	"	Marcy, Piompino Mariano, Bob Marius, Trey Marshall, Dane ",
	"	Martin, Gregg Martin, Renard Martin, Rich Martin, Scott ",
	"	Martin, Thomas Martin, Jon Masters, Christopher Mathews, ",
	"	Jay Mathis, Marc Matthews, Chris Mazur, Doug McBride, ",
	"	Mackey McCandlish, Robin McCollum, Steven McCombie, ",
	"	Andy McConnell, Michael McCourt, Bill McCoy, Doug ",
	"	McCracken, Michael McDeed, Robert McDonald, Steve ",
	"	McEachron, Craig McGee, Ryan McKenzie, Michael McKeown, ",
	"	Daniel McMahon, Colin McMillan, Ian McWilliam, Mark ",
	"	McWilliams, Khann Mean, Bryan Meason, Kenneth Medley, ",
	"	Jeff Meek, John Mehr, Christopher Mende, Brian Mendenhall, ",
	"	Peter Mengel, Michael Mersic, Mike Messom, Don Metcalf, ",
	"	Gary Metzker, Scott Meyer, Joseph Michaud, Andrew Mielke, ",
	"	Travis Mikalson, Troy Milburn, Ike Miller, Ronnie Miller, Sean ",
	"	Miller, Steve Miller, Arthur Min, David Minniti, Brenda ",
	"	Mirsberger, Bill Misek, David Mitchell, Joseph Mobley, Robert ",
	"	Mollard, Will Mooar, Curtis Moore, Matthew Moore, Al ",
	"	Morales, Ryan Moran, Lance Mortensen, Karel Mrazek, Ward ",
	"	Mullee, William Munoz, Kirk Munro, Craig Murray, Shawn P. ",
	"	Murray, Travis Murray, Michael Mushrush, Tom Mustaine, ",
	"	David Myers, Joseph Myett, Morgan Najar, Kenta Nakamura, ",
	"	Damian Nastri, Joshua Naumann, Nick Navarro, Douglas ",
	"	Neitzel, Arnold Ng, Anthony Nguyen, Steve Nguyen, Joseph ",
	"	Nicholas, Charles Nickolaus, Jon Nisbet, Patrick Nomee, David ",
	"	Norling-Christensen, Bobby Norton, Joseph Nottingham, Frank ",
	"	O'Connor, Jon Oden, David Oester, Lavern Ogden, Zach ",
	"	Oglesby, Lucas Oldfield, Toby Olsson, Aaron Ondek, Sean ",
	"	O'Neill, John Orlando, Samuel Orlando, Donovan Orloski, ",
	"	David Pai, Nikolas Paldan, David Palek, John Palmieri, Anthony ",
	"	Palmisano, Sanjay Pandit, Jesse Park, Alex Parker, Jimmy ",
	"	Pasher, Lukasz Paszek, Andy Patterson, William Pelletier, ",
	"	Duane Pemberton, Ivan Pemic, Kelly Pendergast, Mike ",
	"	Penezich, Jon Penk, Willie Penley, Ron Penna, Matthew ",
	"	Pennington, Kevin Pereira, Ross Perez, Ken Perkins, Brian ",
	"	Peterik, Kelly Peterson, Chris Phillips, Rod Pickett, Cameron ",
	"	Pierce, Reuben Pierce, Tim Pilger, Billy Pippin, Brad Plank, ",
	"	Brian Plant, Craig Platt, David Plunkett, Michael Politi, Albert ",
	"	Portillo, Brian Powell, David Powell, Franklin Powers Jr., Alan ",
	"	Precourt, Michael Pronchick, Julian Quintana, Justin Radziej, ",
	"	Steven Rajewski, Shawn Rawles, Ian Reardon, Marc Reed, Ric ",
	"	Reichelt, Judd Reiffin, David Reilly, Garry Reisky, Drew ",
	"	Ressler, Robert Reynolds, Walter Reynolds, Michael Rice, Ian ",
	"	Richards, James Richards, Raymond Richmond, Dustin Riggs, ",
	"	Keith Riskey, Brian Ro, Scott Roberts, Jorge Rodriguez, Chad ",
	"	Rogers, Clint Rogers, Robert Rogers, Steve Rogers, Ethan Roots, ",
	"	Ron Roque, William Ross, Sebastian Rossi, Jeff Rostis, Ben ",
	"	Roth, Demar Roth, Rich Rouse, Oleg Rovner, Jonathan Roy, ",
	"	Drew Rozema, Mike Ruggles, Mathias Russ, James Russell, Jim ",
	"	Rutledge, James Rutter, Dave Ryder, Chris Salvadras, Anders ",
	"	Samnerud, Nick Sanders, Jakob Sandgren, Joe Sapinsky, Tyler ",
	"	Sargent, Jonas Saunders, Mark Savage, Scott Sawyer, Robert ",
	"	Scanlon, Trevor Schaben, Aaron Schmidt, Chris Schmidt, Greg ",
	"	Schultz, Nicholas Schumacher, Scott Schumacher, Kevin Scott, ",
	"	Rastislav Seffer, Robert Seidler, Corey Sellers, Justin Sellers, ",
	"	Marc Senecal, George Shannon, Ian Sheffield, Anoop Shekar, ",
	"	Sandeep Shekar, Kevin Shelton, Leon Shephard, Eric Shepperd, ",
	"	Jeffrey Shneidman, Samuel Shockey, Mark Shoemaker, Mike ",
	"	Shupe, Sean Sibbet, Brian Sidharta, Jimmy Sieben, Eric ",
	"	Siemens, William Silva, Jody Simpson, Jatinder Singh, Sonia ",
	"	Siu, Omar Skarsvaag, Tom Skiba, Carl Skow, David Skuse, ",
	"	Robert Slifka, Brent Smith, C. Eric Smith, Jared Smith, Jeffrey ",
	"	Smith, Owen Smith, Shannon Smith, Steven Smith, Edward Smola, ",
	"	Matthew Sneep, Eric Snow, Brad Sobel, Jean-Pierre Solignac, Rasmus ",
	"	Sørensen, Andrew Sorg, Poppy Southcott, Ross Specter, Erik Spencer, ",
	"	Keith Spencer, Chris Springer, Erikson Squier, Dean St. Onge, Stewart ",
	"	Stanfield, John Stanley, Terrence Staton, Benjamin Stein, James ",
	"	Steiner, David Steyer, William Stickney, Chris Stiff, James Stofer, ",
	"	Norm Storch, Patrick Stovall, Brandon Sturgeon, Sean Stutler, Anne ",
	"	Sukprasert, Jamal Sullivan, Bruce Sully, Jay Sung, Park Sung ",
	"	Joon, Stein Sunnarvik, Nathan Surginer, Robert Swaringen, Lee ",
	"	Sweeney, David Szabo, Scott Taft, Christian Takvam, Patrick ",
	"	Talaska, Tadashi Tamaki, Simon Tan, Mark Taraba, Khon-",
	"	Whey Tay, John Taylor, Keith Taylor, Donald Temean, Phillip ",
	"	Tesar, Pete Thao, Brian Thomas, Keith Thomas, Speed Thomas, ",
	"	Miles Thorpe, Paul Thurrott, Mike Timbol, Nicholas Timmins, ",
	"	Tom Tobin, Robert Towster, Hien Tran, Timothy Traviss, Toby ",
	"	Traylor, Tony Treadwell, George Tremoulis, Paul Trinh, Thanh ",
	"	Trinh, Chris Tristan, Brad Truswell, Jason Tryon, Mike Tu, ",
	"	Gernel Tuazon, Eric Tuggle, Mike Turnbull, Lyle Ubben, ",
	"	Amilcar Ubiera, Robert Ulozas, Arie Upton, Mark Van Noy, ",
	"	Matthew Van Sickler, Jake Vantlin, Tony Vasquez, Brady ",
	"	Vauclin, Gianpiero Vecchi, Chad Verrall, Chris Vicente, Brett ",
	"	Vickers, David Vickery, Jonathan Vilante, Simon Vince, Ben ",
	"	Vinson, David Voelkert, Paul Vogt, Nicholas Voorhies, Robert ",
	"	Vreeland, Mike Vrooman, Rick Vuong, Brian Wachhaus, Todd ",
	"	Wachhaus, Caine Wade, Mathew Wadstein, Kenneth Wagenius, ",
	"	Trevor Wagner, John Wagstaff, Asad Wahid, Richard ",
	"	Wahlberg, Helio Wakasugui, Richard Walker, Wilkins Walker, ",
	"	Matthew Wallace, Daniel Walsh, Joel Walters, Andrew Waltz, ",
	"	Tom Wang, Tony Wang, Jay Ward, Jonathan Ward, John ",
	"	Warner, Mark Warren, Matt Washer, Mike Watson, Sean ",
	"	Wattles, Mike Wayne, Christian Wehba, Benjamin Wei, Richard ",
	"	Weight, Cary Wells, David Wenck, Bill Werring, Leonard ",
	"	Wesley, Marlon West, Mikael Westerbacka, Brian Wharry, ",
	"	Chris White, Chris White, Jeremy White, Greg Whitlock, Gary ",
	"	Widener, Marty Wilfried, Israel Wilkinson, Michael Willams, ",
	"	Derek Williams, Sean Willson, Nitzan Wilnai, Jim Wilson, ",
	"	Karsten Wilson, William Wilt, Tim Winn, Brian Winzeler, Matt ",
	"	Wise, Lee Wissmiller, Brendan Wolfe, Daniel Wolpert, Felix ",
	"	Wong, Power Wong, Tony Wong, Tim Wood, Timothy Wood, ",
	"	Jeremy Woods, Michael Woods, Bill Wright, Keith Wright, ",
	"	Patrick Wu, Gang Xie, Robert Yao, Sun Lim Yap, Stephen Yau, ",
	"	Erek Yedwabnick, Christopher Yee, Nick Yee, Juan Yip, David ",
	"	Young, Rob Young, Seth Young, Alex Yu, Terry Zahn, Jia-Ning ",
	"	Zhang, Eric Zieg, Jordan Zielin, Clint Zimmerman, Matt Zinke ",
	"",
	"",
	"",
	"",
	"	No souls were sold in the making of this game.",
	"",
	"",
	" ",
	" ",
	" ",
	NULL
};

void credts_Load()
{
	LoadBackgroundArt("ui_art\\credits.pcx");
}

void credts_Free()
{
	mem_free_dbg(ArtBackground.data);
	ArtBackground.data = NULL;
}

void credts_Render()
{
	DrawArt(0, 0, &ArtBackground);

	int lineHeight = 22;

	ybase = GetAnimationFrame(lineHeight, 40);

	if (lastYbase != ybase && ybase == 0) {
		if (creditEnd) {
			lineCount--;
			creditLine++;
		} else {
			if (the_long_credits[creditLine + CREDIT_LINES + 1] == NULL) {
				creditEnd = true;
			}
			creditLine++;
		}
	}
	lastYbase = ybase;

	if (font != NULL) {
		SDL_Color color = palette->colors[224];
		SDL_Surface *text_surface;
		for (int i = 0; i < lineCount; i++) {
			if (creditLine + i < 0) {
				continue;
			}

			int offset = 0;
			int x = 31;
			int y = (i * lineHeight) - ybase - lineHeight;
			if (*the_long_credits[creditLine + i] == '	') {
				offset = 1;
				x += 40;
			}

			if (text_surface = TTF_RenderUTF8_Solid(font, the_long_credits[creditLine + i] + offset, color)) {
				SDL_Rect src_rect = { 0, -y, SCREEN_WIDTH, 251 };
				SDL_Rect dsc_rect = { 64 + x, 160 + 114, SCREEN_WIDTH, SCREEN_HEIGHT };
				SDL_BlitSurface(text_surface, &src_rect, pal_surface, &dsc_rect);
				SDL_FreeSurface(text_surface);
			}
		}
	}
}

BOOL __stdcall UiCreditsDialog(int a1)
{
	credts_Load();

	creditEnd = false;
	lineCount = CREDIT_LINES;
	creditLine = -lineCount;
	lastYbase = 0;
	bool endMenu = false;

	SDL_Event event;
	while (!endMenu && lineCount > 0) {
		CapFPS();
		credts_Render();
		UiFadeIn();

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
			case SDL_MOUSEBUTTONDOWN:
				endMenu = true;
				break;
			case SDL_QUIT:
				exit(0);
			}
		}
	}
	BlackPalette();

	credts_Free();

	return TRUE;
}
